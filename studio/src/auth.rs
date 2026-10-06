//! Who a request acts for. Three gates, one per way of running:
//!
//! * `Token` (local mode): the one user, `local`, proves itself with the
//!   launch token, carried in the page's fragment and sent with the
//!   WebSocket handshake.
//! * `Login` (server mode): users log in with a password at `/login`, which
//!   sets a session cookie (`HttpOnly; SameSite=Lax`); sessions persist in
//!   the data directory (`accounts.rs`).
//! * `Proxy` (server mode, `TRUST_PROXY_AUTH`): a reverse proxy has already
//!   authenticated the request and names the user in `Remote-User`. The
//!   proxy must strip any `Remote-User` a client sends, and the studio must
//!   not be reachable except through it.
//!
//! Only the WebSocket reads or changes a project, so it is the one guarded
//! route; it also requires a same-origin `Origin`, since browsers send
//! cookies on cross-site WebSocket handshakes. The page holds no data; under
//! a login it is still sent only to the logged in, with their name and a way
//! to log out. TLS is the reverse proxy's job.

use crate::accounts::{Accounts, SESSION_LIFETIME};
use crate::registry::{LOCAL_USER, valid_name};
use crate::web::field;
use axum::Router;
use axum::extract::State;
use axum::http::{HeaderMap, StatusCode, Uri, header};
use axum::response::{IntoResponse, Redirect, Response};
use axum::routing::{get, post};
use std::sync::Arc;
use std::time::Duration;

const COOKIE: &str = "slog_studio_session";

/// Where the page shows who is logged in.
const ACCOUNT_SLOT: &str = "<!--account-->";

pub enum Gate {
    Token(String),
    Login(Arc<Accounts>),
    Proxy,
}

impl Gate {
    /// The user a WebSocket handshake acts for, if it may act at all. The
    /// caller checks its origin too.
    pub fn socket_user(&self, uri: &Uri, headers: &HeaderMap) -> Option<String> {
        match self {
            Gate::Token(token) => uri
                .query()
                .and_then(|query| field(query, "token"))
                .is_some_and(|given| same_secret(&given, token))
                .then(|| LOCAL_USER.to_owned()),
            Gate::Login(_) | Gate::Proxy => self.login(headers),
        }
    }

    /// The studio page, `html`. Under a login it names the user and offers
    /// to log out, and the logged out are sent to log in.
    pub fn page(&self, headers: &HeaderMap, html: &str) -> Response {
        let account = match (self, self.login(headers)) {
            (Gate::Token(_), _) => String::new(),
            (Gate::Login(_), Some(user)) => format!(
                r#"<form id="account" class="account" method="post" action="/logout"><span>{user}</span><button class="small">Log out</button></form>"#
            ),
            (Gate::Proxy, Some(user)) => {
                format!(r#"<span id="account" class="account">{user}</span>"#)
            }
            (Gate::Login(_), None) => return Redirect::to("/login").into_response(),
            (Gate::Proxy, None) => {
                return (StatusCode::UNAUTHORIZED, "the proxy did not name a user").into_response();
            }
        };
        page(html.replace(ACCOUNT_SLOT, &account))
    }

    /// The login and logout routes, when the gate has them.
    pub fn routes(&self) -> Router {
        match self {
            Gate::Login(accounts) => Router::new()
                .route("/login", get(|| async { login_page("") }).post(login))
                .route("/logout", post(logout))
                .with_state(accounts.clone()),
            Gate::Token(_) | Gate::Proxy => Router::new(),
        }
    }

    /// The logged-in user, under a login or a proxy. Only a valid name
    /// counts: it becomes a directory, and it is written into the page.
    fn login(&self, headers: &HeaderMap) -> Option<String> {
        let user = match self {
            Gate::Token(_) => None,
            Gate::Login(accounts) => {
                session_secret(headers).and_then(|secret| accounts.session_user(secret))
            }
            Gate::Proxy => headers
                .get("remote-user")
                .and_then(|value| value.to_str().ok())
                .map(str::to_owned),
        }?;
        valid_name(&user).then_some(user)
    }
}

fn page(html: String) -> Response {
    (
        [
            (header::CONTENT_TYPE, "text/html; charset=utf-8"),
            (header::CACHE_CONTROL, "no-cache"),
        ],
        html,
    )
        .into_response()
}

fn login_page(error: &str) -> Response {
    page(include_str!("../web/login.html").replace("<!--error-->", error))
}

async fn login(
    State(accounts): State<Arc<Accounts>>,
    headers: HeaderMap,
    body: String,
) -> Response {
    if !same_origin(&headers) {
        return StatusCode::FORBIDDEN.into_response();
    }
    let user = field(&body, "user").unwrap_or_default();
    let password = field(&body, "password").unwrap_or_default();
    let verified = {
        let (accounts, user) = (accounts.clone(), user.clone());
        tokio::task::spawn_blocking(move || accounts.verify(&user, &password))
            .await
            .unwrap_or(false)
    };
    if !verified {
        // One guess a second per connection.
        tokio::time::sleep(Duration::from_secs(1)).await;
        let mut refused = login_page("Wrong name or password.");
        *refused.status_mut() = StatusCode::UNAUTHORIZED;
        return refused;
    }
    let secret = match accounts.start_session(&user) {
        Ok(secret) => secret,
        Err(message) => return (StatusCode::INTERNAL_SERVER_ERROR, message).into_response(),
    };
    // Behind a TLS proxy the cookie need never travel in the clear.
    let https = headers
        .get("x-forwarded-proto")
        .is_some_and(|proto| proto.as_bytes() == b"https");
    let cookie = format!(
        "{COOKIE}={secret}; Path=/; HttpOnly; SameSite=Lax; Max-Age={}{}",
        SESSION_LIFETIME.as_secs(),
        if https { "; Secure" } else { "" }
    );
    ([(header::SET_COOKIE, cookie)], Redirect::to("/")).into_response()
}

async fn logout(State(accounts): State<Arc<Accounts>>, headers: HeaderMap) -> Response {
    if !same_origin(&headers) {
        return StatusCode::FORBIDDEN.into_response();
    }
    if let Some(secret) = session_secret(&headers) {
        accounts.end_session(secret);
    }
    let cookie = format!("{COOKIE}=; Path=/; HttpOnly; SameSite=Lax; Max-Age=0");
    ([(header::SET_COOKIE, cookie)], Redirect::to("/login")).into_response()
}

fn session_secret(headers: &HeaderMap) -> Option<&str> {
    headers
        .get_all(header::COOKIE)
        .iter()
        .filter_map(|value| value.to_str().ok())
        .flat_map(|cookies| cookies.split(';'))
        .find_map(|cookie| cookie.trim().strip_prefix(COOKIE)?.strip_prefix('='))
}

/// Whether the request comes from a page this server served: its `Origin`
/// names the host it was sent to, over plain HTTP or HTTPS at a proxy.
/// Browsers send cookies cross-site on WebSocket handshakes and form posts,
/// so those must pass this.
pub fn same_origin(headers: &HeaderMap) -> bool {
    let value = |name| headers.get(name).and_then(|value| value.to_str().ok());
    match (value(header::ORIGIN), value(header::HOST)) {
        (Some(origin), Some(host)) => ["http://", "https://"]
            .iter()
            .any(|scheme| origin.strip_prefix(scheme) == Some(host)),
        _ => false,
    }
}

/// Comparison whose time does not depend on where the inputs differ.
pub(crate) fn same_secret(given: &str, expected: &str) -> bool {
    given.len() == expected.len()
        && given
            .bytes()
            .zip(expected.bytes())
            .fold(0, |difference, (a, b)| difference | (a ^ b))
            == 0
}

#[cfg(test)]
mod tests {
    use super::{COOKIE, Gate, LOCAL_USER, same_origin, same_secret};
    use crate::accounts::{Accounts, private_dir};
    use axum::http::{HeaderMap, HeaderValue, Uri, header};
    use std::sync::Arc;

    #[test]
    fn the_socket_accepts_only_its_own_origin() {
        let headers = |origin: &'static str| {
            let mut headers = HeaderMap::new();
            headers.insert(header::HOST, HeaderValue::from_static("127.0.0.1:7300"));
            headers.insert(header::ORIGIN, HeaderValue::from_static(origin));
            headers
        };
        assert!(same_origin(&headers("http://127.0.0.1:7300")));
        assert!(same_origin(&headers("https://127.0.0.1:7300")));
        assert!(!same_origin(&headers("http://evil.example")));
        assert!(!same_origin(&headers("http://127.0.0.1:7301")));
        assert!(!same_origin(&headers("ftp://127.0.0.1:7300")));
        assert!(!same_origin(&HeaderMap::new()));
        assert!(same_secret("abc", "abc"));
        assert!(!same_secret("abd", "abc"));
        assert!(!same_secret("ab", "abc"));
    }


    /// Each gate admits a handshake on its own credential only: the launch
    /// token, a live session cookie, or a proxy's valid `Remote-User`.
    #[test]
    fn the_socket_admits_only_its_gates_credential() {
        let uri = |query: &str| format!("/ws?{query}").parse::<Uri>().expect("uri");
        let header = |name, value: &str| {
            let mut headers = HeaderMap::new();
            headers.insert(name, HeaderValue::from_str(value).expect("header"));
            headers
        };
        let none = HeaderMap::new();

        let token = Gate::Token("ab".repeat(32));
        let local = token.socket_user(&uri(&format!("project=&token={}", "ab".repeat(32))), &none);
        assert_eq!(local.as_deref(), Some(LOCAL_USER));
        assert_eq!(
            token.socket_user(&uri(&format!("token={}", "ab".repeat(31))), &none),
            None
        );

        let data = std::env::temp_dir().join(format!("studio-gate-{}", std::process::id()));
        let _ = std::fs::remove_dir_all(&data);
        private_dir(&data).expect("data directory");
        let accounts = Arc::new(Accounts::new(data.clone()));
        accounts.add_user("alice", "pw").expect("add alice");
        let secret = accounts.start_session("alice").expect("login");
        let login = Gate::Login(accounts.clone());
        let cookie = |value: &str| header(header::COOKIE, &format!("theme=dark; {COOKIE}={value}"));
        assert_eq!(
            login.socket_user(&uri(""), &cookie(&secret)).as_deref(),
            Some("alice")
        );
        assert_eq!(login.socket_user(&uri(""), &cookie("0")), None);
        assert_eq!(
            login.socket_user(&uri(""), &header(header::HOST, "x")),
            None
        );
        // The launch token means nothing to a login gate, nor a login to a proxy.
        assert_eq!(
            login.socket_user(&uri(&format!("token={secret}")), &none),
            None
        );
        assert_eq!(Gate::Proxy.socket_user(&uri(""), &cookie(&secret)), None);

        let remote = |user: &str| {
            Gate::Proxy.socket_user(
                &uri(""),
                &header(header::HeaderName::from_static("remote-user"), user),
            )
        };
        assert_eq!(remote("bob").as_deref(), Some("bob"));
        assert_eq!(remote("../bob"), None);
        assert_eq!(remote(""), None);
        std::fs::remove_dir_all(data).expect("cleanup");
    }
}

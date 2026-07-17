use crate::version;
use serde::Serialize;
use std::fs;
use std::io;
use std::os::unix::fs::PermissionsExt;
use std::path::{Path, PathBuf};
use std::sync::{Arc, RwLock};
use std::time::{SystemTime, UNIX_EPOCH};
use tokio::io::{AsyncBufReadExt, AsyncWriteExt, BufReader};
use tokio::net::{TcpListener, TcpStream};
use tokio::sync::{broadcast, mpsc};
use tokio::task::JoinHandle;

const SHARE_PROTOCOL: u64 = 1;
const MAX_INPUT_BYTES: usize = 64 * 1024;
const DISCOVERY_DIR: &str = "/tmp";

#[derive(Clone, Debug)]
struct OutboundMessage {
    target: Option<u64>,
    text: String,
}

#[derive(Clone, Debug)]
pub struct DirectReply {
    client_id: u64,
    outbound: broadcast::Sender<OutboundMessage>,
}

impl DirectReply {
    pub fn send(&self, message: String) -> bool {
        self.outbound
            .send(OutboundMessage {
                target: Some(self.client_id),
                text: message,
            })
            .is_ok()
    }
}

#[derive(Debug)]
pub enum ShareEvent {
    Connected {
        peer: String,
    },
    Disconnected {
        peer: String,
    },
    Input {
        peer: String,
        text: String,
        reply: DirectReply,
    },
}

#[derive(Clone, Debug, Serialize)]
struct DiscoveryRecord {
    protocol: u64,
    slog_version: String,
    pid: u32,
    endpoint: String,
    project_root: String,
    started_unix: u64,
    current: Option<String>,
}

pub struct ShareServer {
    pub events: mpsc::Receiver<ShareEvent>,
    outbound: broadcast::Sender<OutboundMessage>,
    endpoint: String,
    registry_path: PathBuf,
    discovery: DiscoveryRecord,
    snapshot: Arc<RwLock<String>>,
    task: JoinHandle<()>,
}

impl ShareServer {
    pub async fn start(project_root: &Path) -> Result<Self, String> {
        let listener = TcpListener::bind("127.0.0.1:0")
            .await
            .map_err(|error| format!("cannot open co-author socket: {error}"))?;
        let address = listener
            .local_addr()
            .map_err(|error| format!("cannot inspect co-author socket: {error}"))?;
        let endpoint = address.to_string();
        let registry_path = Path::new(DISCOVERY_DIR).join(format!(
            "slog-repl.{}.{}.json",
            std::process::id(),
            address.port()
        ));
        let discovery = DiscoveryRecord {
            protocol: SHARE_PROTOCOL,
            slog_version: version::current().to_owned(),
            pid: std::process::id(),
            endpoint: endpoint.clone(),
            project_root: project_root.display().to_string(),
            started_unix: SystemTime::now()
                .duration_since(UNIX_EPOCH)
                .unwrap_or_default()
                .as_secs(),
            current: None,
        };
        write_discovery(&registry_path, &discovery)
            .map_err(|error| format!("cannot publish co-author discovery record: {error}"))?;

        let (events_tx, events_rx) = mpsc::channel(64);
        let (outbound, _) = broadcast::channel(256);
        let snapshot = Arc::new(RwLock::new(String::new()));
        let task = tokio::spawn(run_listener(
            listener,
            events_tx,
            outbound.clone(),
            snapshot.clone(),
            endpoint.clone(),
            registry_path.display().to_string(),
        ));
        Ok(Self {
            events: events_rx,
            outbound,
            endpoint,
            registry_path,
            discovery,
            snapshot,
            task,
        })
    }

    pub fn endpoint(&self) -> &str {
        &self.endpoint
    }

    pub fn registry_path(&self) -> &Path {
        &self.registry_path
    }

    pub fn publish(&self, message: impl Into<String>) {
        let _ = self.outbound.send(OutboundMessage {
            target: None,
            text: message.into(),
        });
    }

    pub fn set_snapshot(&self, snapshot: String) {
        *self
            .snapshot
            .write()
            .unwrap_or_else(|poisoned| poisoned.into_inner()) = snapshot;
    }

    pub fn set_current(&mut self, current: Option<&str>) -> Result<(), String> {
        if self.discovery.current.as_deref() == current {
            return Ok(());
        }
        self.discovery.current = current.map(str::to_owned);
        write_discovery(&self.registry_path, &self.discovery)
            .map_err(|error| format!("cannot update co-author discovery record: {error}"))
    }
}

impl Drop for ShareServer {
    fn drop(&mut self) {
        self.task.abort();
        let _ = fs::remove_file(&self.registry_path);
    }
}

fn write_discovery(path: &Path, discovery: &DiscoveryRecord) -> io::Result<()> {
    let body = serde_json::to_vec_pretty(discovery)
        .map_err(|error| io::Error::new(io::ErrorKind::InvalidData, error))?;
    let temporary = path.with_extension("json.tmp");
    fs::write(&temporary, body)?;
    fs::set_permissions(&temporary, fs::Permissions::from_mode(0o644))?;
    fs::rename(temporary, path)
}

async fn run_listener(
    listener: TcpListener,
    events: mpsc::Sender<ShareEvent>,
    outbound: broadcast::Sender<OutboundMessage>,
    snapshot: Arc<RwLock<String>>,
    endpoint: String,
    registry_path: String,
) {
    let mut next_client_id = 1_u64;
    while let Ok((stream, address)) = listener.accept().await {
        let client_id = next_client_id;
        next_client_id = next_client_id.wrapping_add(1);
        let events = events.clone();
        let direct = DirectReply {
            client_id,
            outbound: outbound.clone(),
        };
        let outbound = outbound.subscribe();
        let snapshot = snapshot.clone();
        let endpoint = endpoint.clone();
        let registry_path = registry_path.clone();
        tokio::spawn(async move {
            run_connection(
                stream,
                ConnectionContext {
                    client_id,
                    address: address.to_string(),
                    events,
                    outbound,
                    direct,
                    snapshot,
                    endpoint,
                    registry_path,
                },
            )
            .await;
        });
    }
}

struct ConnectionContext {
    client_id: u64,
    address: String,
    events: mpsc::Sender<ShareEvent>,
    outbound: broadcast::Receiver<OutboundMessage>,
    direct: DirectReply,
    snapshot: Arc<RwLock<String>>,
    endpoint: String,
    registry_path: String,
}

async fn run_connection(stream: TcpStream, context: ConnectionContext) {
    let ConnectionContext {
        client_id,
        address,
        events,
        mut outbound,
        direct,
        snapshot,
        endpoint,
        registry_path,
    } = context;
    let (reader, mut writer) = stream.into_split();
    let banner = format!(
        "SLOG-COAUTHOR/{SHARE_PROTOCOL}\nendpoint: {endpoint}\ndiscovery: {registry_path}\ninput: COMMAND (shared), `; comment`, or `/private COMMAND`; `/name NAME` identifies you\n"
    );
    if writer.write_all(banner.as_bytes()).await.is_err() {
        return;
    }
    let initial = snapshot
        .read()
        .unwrap_or_else(|poisoned| poisoned.into_inner())
        .clone();
    if !initial.is_empty()
        && writer
            .write_all(format!("--- transcript snapshot ---\n{initial}\n--- live ---\n").as_bytes())
            .await
            .is_err()
    {
        return;
    }

    let mut peer = address;
    let _ = events
        .send(ShareEvent::Connected { peer: peer.clone() })
        .await;
    let mut lines = BufReader::new(reader).lines();
    loop {
        tokio::select! {
            incoming = lines.next_line() => {
                let Ok(Some(text)) = incoming else { break };
                if text.len() > MAX_INPUT_BYTES {
                    if writer.write_all(b"! input line exceeds 64 KiB\n").await.is_err() {
                        break;
                    }
                    continue;
                }
                if let Some(name) = text.strip_prefix("/name ") {
                    let name = name.trim();
                    if !name.is_empty() {
                        peer = name.chars().take(80).collect();
                        if writer
                            .write_all(format!("• identified as {peer}\n").as_bytes())
                            .await
                            .is_err()
                        {
                            break;
                        }
                    }
                    continue;
                }
                if events
                    .send(ShareEvent::Input {
                        peer: peer.clone(),
                        text,
                        reply: direct.clone(),
                    })
                    .await
                    .is_err()
                {
                    break;
                }
            }
            outgoing = outbound.recv() => {
                match outgoing {
                    Ok(message) => {
                        if message.target.is_some_and(|target| target != client_id) {
                            continue;
                        }
                        if writer.write_all(message.text.as_bytes()).await.is_err()
                            || writer.write_all(b"\n").await.is_err()
                        {
                            break;
                        }
                    }
                    Err(broadcast::error::RecvError::Lagged(amount)) => {
                        if writer
                            .write_all(format!("! skipped {amount} co-author messages\n").as_bytes())
                            .await
                            .is_err()
                        {
                            break;
                        }
                    }
                    Err(broadcast::error::RecvError::Closed) => break,
                }
            }
        }
    }
    let _ = events.send(ShareEvent::Disconnected { peer }).await;
}

#[cfg(test)]
mod tests {
    use super::{DiscoveryRecord, SHARE_PROTOCOL, ShareEvent, ShareServer, version};
    use std::os::unix::fs::PermissionsExt;
    use std::path::Path;
    use tokio::io::{AsyncBufReadExt, AsyncWriteExt, BufReader};
    use tokio::net::TcpStream;
    use tokio::time::{Duration, timeout};

    #[test]
    fn discovery_record_is_self_describing_json() {
        let record = DiscoveryRecord {
            protocol: SHARE_PROTOCOL,
            slog_version: version::current().to_owned(),
            pid: 42,
            endpoint: "127.0.0.1:34567".to_owned(),
            project_root: "/work/slog".to_owned(),
            started_unix: 100,
            current: Some("example".to_owned()),
        };
        let value = serde_json::to_value(record).expect("serialize discovery");
        assert_eq!(value["protocol"], 1);
        assert_eq!(value["slog_version"], version::current());
        assert_eq!(value["endpoint"], "127.0.0.1:34567");
        assert_eq!(value["current"], "example");
    }

    #[tokio::test]
    async fn peer_receives_snapshot_and_can_identify_before_sending_input() {
        let mut server = ShareServer::start(Path::new("/work/slog"))
            .await
            .expect("start co-author server");
        server.set_snapshot("◆ Existing result".to_owned());
        let registry = server.registry_path().to_owned();
        assert_eq!(
            std::fs::metadata(&registry)
                .expect("discovery metadata")
                .permissions()
                .mode()
                & 0o777,
            0o644
        );

        let stream = TcpStream::connect(server.endpoint())
            .await
            .expect("connect co-author");
        let (reader, mut writer) = stream.into_split();
        let mut lines = BufReader::new(reader).lines();
        let mut received = Vec::new();
        for _ in 0..7 {
            received.push(
                lines
                    .next_line()
                    .await
                    .expect("read banner")
                    .expect("banner line"),
            );
        }
        assert_eq!(received[0], "SLOG-COAUTHOR/1");
        assert_eq!(received[4], "--- transcript snapshot ---");
        assert_eq!(received[5], "◆ Existing result");
        assert_eq!(received[6], "--- live ---");
        assert!(matches!(
            server.events.recv().await,
            Some(ShareEvent::Connected { .. })
        ));

        writer
            .write_all(b"/name codex\n; inspect edge\n")
            .await
            .expect("send co-author input");
        assert_eq!(
            lines
                .next_line()
                .await
                .expect("read identity acknowledgement")
                .as_deref(),
            Some("• identified as codex")
        );
        let reply = match server.events.recv().await {
            Some(ShareEvent::Input {
                peer, text, reply, ..
            }) if peer == "codex" && text == "; inspect edge" => reply,
            other => panic!("unexpected input event: {other:?}"),
        };

        let observer = TcpStream::connect(server.endpoint())
            .await
            .expect("connect observing co-author");
        let (observer_reader, _observer_writer) = observer.into_split();
        let mut observer_lines = BufReader::new(observer_reader).lines();
        for _ in 0..7 {
            observer_lines
                .next_line()
                .await
                .expect("read observer banner")
                .expect("observer banner line");
        }
        assert!(matches!(
            server.events.recv().await,
            Some(ShareEvent::Connected { .. })
        ));

        assert!(reply.send("◆ Private result".to_owned()));
        assert_eq!(
            lines
                .next_line()
                .await
                .expect("read targeted output")
                .as_deref(),
            Some("◆ Private result")
        );
        assert!(
            timeout(Duration::from_millis(50), observer_lines.next_line())
                .await
                .is_err(),
            "targeted output leaked to another co-author"
        );

        drop(server);
        assert!(!registry.exists());
    }
}

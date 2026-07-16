use serde::{Deserialize, Serialize};
use serde_json::{Value, json};
use std::io;
use tokio::io::{AsyncBufReadExt, AsyncReadExt, AsyncWriteExt, BufReader};
use tokio::net::TcpStream;
use tokio::net::tcp::{OwnedReadHalf, OwnedWriteHalf};

pub const PROTOCOL_VERSION: u64 = 1;
const MAX_FRAME_BYTES: usize = 16 * 1024 * 1024;

#[derive(Debug, Deserialize)]
pub struct Announcement {
    pub host: String,
    pub port: u16,
    pub protocol: u64,
}

#[derive(Debug, Serialize)]
struct Request {
    id: u64,
    method: String,
    params: Value,
}

#[derive(Clone, Debug, Deserialize)]
pub struct ServerError {
    pub kind: String,
    pub message: String,
}

#[derive(Clone, Debug, Deserialize)]
pub struct Response {
    pub id: u64,
    pub ok: bool,
    #[serde(default)]
    pub result: Option<Value>,
    #[serde(default)]
    pub error: Option<ServerError>,
}

pub struct SessionConnection {
    reader: BufReader<OwnedReadHalf>,
    writer: OwnedWriteHalf,
    next_id: u64,
}

impl SessionConnection {
    pub async fn connect(address: &str, token: &str) -> io::Result<Self> {
        let stream = TcpStream::connect(address).await?;
        stream.set_nodelay(true)?;
        let (reader, writer) = stream.into_split();
        let mut connection = Self {
            reader: BufReader::new(reader),
            writer,
            next_id: 1,
        };
        let response = connection
            .request(
                "hello",
                json!({"token": token, "protocol": PROTOCOL_VERSION}),
            )
            .await?;
        if !response.ok {
            return Err(io::Error::new(
                io::ErrorKind::PermissionDenied,
                response
                    .error
                    .map(|error| error.message)
                    .unwrap_or_else(|| "REPL handshake rejected".to_owned()),
            ));
        }
        Ok(connection)
    }

    pub async fn command(&mut self, line: String) -> io::Result<Response> {
        self.request("command", json!({"line": line})).await
    }

    pub async fn shutdown(&mut self) -> io::Result<Response> {
        self.request("shutdown", json!({})).await
    }

    async fn request(&mut self, method: &str, params: Value) -> io::Result<Response> {
        let id = self.next_id;
        self.next_id += 1;
        let request = Request {
            id,
            method: method.to_owned(),
            params,
        };
        write_frame(&mut self.writer, &request).await?;
        let response: Response = read_frame(&mut self.reader).await?;
        if response.id != id {
            return Err(io::Error::new(
                io::ErrorKind::InvalidData,
                format!("response id {} does not match request {id}", response.id),
            ));
        }
        Ok(response)
    }
}

async fn write_frame<T: Serialize>(writer: &mut OwnedWriteHalf, value: &T) -> io::Result<()> {
    let body = serde_json::to_vec(value)
        .map_err(|error| io::Error::new(io::ErrorKind::InvalidData, error))?;
    if body.len() > MAX_FRAME_BYTES {
        return Err(io::Error::new(
            io::ErrorKind::InvalidInput,
            "protocol frame exceeds configured limit",
        ));
    }
    writer
        .write_all(format!("Content-Length: {}\r\n\r\n", body.len()).as_bytes())
        .await?;
    writer.write_all(&body).await?;
    writer.flush().await
}

async fn read_frame<T: for<'de> Deserialize<'de>>(
    reader: &mut BufReader<OwnedReadHalf>,
) -> io::Result<T> {
    let mut header = String::new();
    if reader.read_line(&mut header).await? == 0 {
        return Err(io::Error::new(
            io::ErrorKind::UnexpectedEof,
            "REPL server closed the connection",
        ));
    }
    let amount = header
        .trim_end_matches(['\r', '\n'])
        .strip_prefix("Content-Length:")
        .and_then(|value| value.trim().parse::<usize>().ok())
        .filter(|amount| *amount <= MAX_FRAME_BYTES)
        .ok_or_else(|| io::Error::new(io::ErrorKind::InvalidData, "invalid frame header"))?;
    let mut separator = String::new();
    reader.read_line(&mut separator).await?;
    if separator != "\r\n" && separator != "\n" {
        return Err(io::Error::new(
            io::ErrorKind::InvalidData,
            "missing frame header terminator",
        ));
    }
    let mut body = vec![0; amount];
    reader.read_exact(&mut body).await?;
    serde_json::from_slice(&body).map_err(|error| io::Error::new(io::ErrorKind::InvalidData, error))
}

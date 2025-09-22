1.  **Principles of Network Applications**
    *   **Application Architectures**:[1]
        *   Client-Server Paradigm: An always-on server handles requests from multiple clients.
        *   Peer-to-Peer (P2P) Architecture: Arbitrary end systems communicate directly with each other without a dedicated server.
    *   **Process Communication**:[1]
        *   Processes on different hosts communicate by exchanging messages.
        *   Sockets act as the "door" through which processes send and receive messages.
        *   Processes are addressed using both an IP address and a port number.
    *   **Application-Layer Protocols**: Defines message types, syntax, semantics, and rules for communication.[1]
    *   **Transport Layer Services**:[1]
        *   Applications have different needs regarding data integrity, throughput, timing, and security.
        *   **TCP Service**: Provides reliable, connection-oriented transport with flow and congestion control.
        *   **UDP Service**: Offers unreliable, connectionless "best-effort" data transfer.
        *   **Transport Layer Security (TLS)**: An application-layer implementation that provides encryption, data integrity, and authentication for TCP connections.[1]

2.  **Web and HTTP (HyperText Transfer Protocol)**
    *   **Overview**: An application-layer protocol that follows a client-server model. It is "stateless," meaning the server doesn't retain information about past client requests.[1]
    *   **HTTP Connections**:[1]
        *   **Non-Persistent HTTP**: A separate TCP connection is used for each object (e.g., HTML file, image), resulting in higher overhead.
        *   **Persistent HTTP**: A single TCP connection is used to transfer multiple objects between a client and server.
    *   **HTTP Messages**:[1]
        *   **Request Message**: Includes methods like `GET`, `POST`, `HEAD`, and `PUT`.
        *   **Response Message**: Contains status codes (e.g., `200 OK`, `404 Not Found`) and the requested data.
    *   **State Management with Cookies**: Used to maintain user state (like shopping carts or login sessions) across multiple requests by storing data on the client's machine.[1]
    *   **Web Caching (Proxy Servers)**: Caches store copies of objects closer to users to reduce response time, decrease network traffic, and improve content delivery efficiency.[1]
    *   **HTTP/2 and HTTP/3 (QUIC)**: Evolutions of HTTP designed to reduce latency by mitigating head-of-line blocking and speeding up connection establishment.[1]

3.  **E-mail: SMTP and IMAP**
    *   **Components**: User Agents (mail readers), Mail Servers, and the Simple Mail Transfer Protocol (SMTP).[1]
    *   **SMTP (Simple Mail Transfer Protocol)**: A "push" protocol that uses TCP to send e-mail messages from a client's mail server to the recipient's mail server.[1]
    *   **Mail Access Protocols**:[1]
        *   **IMAP (Internet Mail Access Protocol)**: Allows users to retrieve and manage messages stored on a server.
        *   **HTTP**: Used by web-based email clients (like Gmail) to send and retrieve messages.

4.  **DNS (Domain Name System)**
    *   **Function**: A distributed, hierarchical database that translates human-readable hostnames (e.g., `www.google.com`) into machine-readable IP addresses.[1]
    *   **Structure**: Comprises Root DNS servers, Top-Level Domain (TLD) servers (for `.com`, `.org`, etc.), and authoritative DNS servers for specific domains.[1]
    *   **Name Resolution**:[1]
        *   **Iterated Query**: The local DNS server queries each server in the hierarchy directly.
        *   **Recursive Query**: The local DNS server tasks the next server in the hierarchy to find the answer on its behalf.
    *   **DNS Caching**: Servers cache name-to-address mappings to speed up subsequent requests.[1]
    *   **DNS Records**: Includes record types like `A` (address), `NS` (name server), `CNAME` (alias), and `MX` (mail exchange).[1]
    *   **Security**: Vulnerable to DDoS attacks and spoofing (DNS cache poisoning).[1]

5.  **Video Streaming and Content Distribution Networks (CDNs)**
    *   **Video Basics**: Video is encoded to reduce its size using spatial (within an image) and temporal (between images) coding.[1]
    *   **DASH (Dynamic Adaptive Streaming over HTTP)**: The client intelligently requests video chunks at different quality levels based on available network bandwidth.[1]
    *   **CDNs**: A geographically distributed network of servers that store copies of content closer to users to improve streaming performance and scalability. Netflix's OpenConnect is a primary example.[1]

6.  **Socket Programming**
    *   **Overview**: How to build client/server applications that communicate using sockets.[1]
    *   **Socket Programming with UDP**: Involves creating sockets without a formal connection, where each packet must contain the destination address and port.[1]
    *   **Socket Programming with TCP**: Involves establishing a dedicated connection between the client and server, providing a reliable, stream-oriented "pipe" for data transfer.[1]

[1](https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/attachments/81615547/f5650a42-8930-48dc-afb2-a4f699ffd10f/Chapter_2_v9.0.pptx)

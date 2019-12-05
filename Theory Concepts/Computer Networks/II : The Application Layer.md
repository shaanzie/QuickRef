# The Application Layer

## Principles of Network Applications

### Network Application Architectures

In a client server architecture, there is an always-on-host, called the server, which services requests from many other hosts, called clients. In a P2P architecture, there is minimal or no reliance on dedicated servers. Instead, the application exploits direct communication between pairs of intermittently connected hosts, called peers.

P2P architectures are self scalable and cost effective but,
1. Not ISP friendly (asymmetrical bandwidth usage)
2. Security issues
3. No incentives

### Processes Communicating

Processes on two systems communicate using messages accross the network. The software interface from which messages are sent/received are called sockets. 
The only control that the application layer has with the transport is the protocol to use and the parameters to be modified.

To identify receiving processes, the address of the host and the IP of the receiver must be sent.

### Transport Services 

If a protocol provides a guarantee that the data sent by one end of the application is delivered to the other end, it is said to be a reliable protocol. Reliable protocols ensure a throughput guaranteed is always exceeded. Usually this is preferred by bandwidth sensitive applications.
Elastic applicatons make use of whatever throughput is available to them.

The Transmission Control Protocol service model includes a connection oriented service with reliable data transfer.
A handshake occurs before the messages are sent/received between sockets, hence, making the service connection-ortiented.

User Datagram Protocol is a no-frills, lightweight transfer protocol, which is connectionless, so there is no handshaking.

Throughput and timing guarantees are not provided by TCP or by UDP.

An application layer protocol defines how an application's processes running on different end systems communicate with each other. The protocol defines
1. Type of message
2. Syntax of message
3. Semantics of message
4. Rules for determining how and when these messages are sent

## The Web and HTTP

The Hypertext Transfer Protocol is the Web's application layer protocol. HTTP uses TCP as the underlying protocol, and sends HTTP requests into sockets and receives the same.
Since HTTP retains no information about the client, it is said to be stateless. 

The round trip time is the time taken for a small packet to travel from client to server and back to client. The RTT includes packet propogation, queuing and processing delays. 

When a request is made, a 3 - way handshake occurs where the client sends a small TCP segment to the server, the server acknowledges and responds with another segment and then the client acknowledges back to the server. After the RTT, the client sends the request message with the third acknowledgement.

### Non Persistent and Persistent Connections

In non persistent connections, each TCP connection closes after the server sends an object and does not persist for other objects. The drawbacks of non persistence are:
1. Brand new connections to be established and maintained for each object
2. Delivery delay of 2 RTTs

In persistent connections, the same stream is used for multiple objects. The requests can be made back-to-back, without waiting for replies to pending requests (pipelining).

### HTTP Message Format

#### Request Header Fields

1. Request line : (method, url, HTTP version)
2. Host: Specifies the host on which the object resides
3. Connection: Specifies persistence or non-persistence
4. User-Agent: Specifies user-agent
5. Accept-language: Content negotiation

#### Response Header Fields

1. Status line: (Protocol version, status, status message)
2. Connection
3. Date
4. Server: Server the message was generated from
5. Last-Modified: When the object was created or last modified (used for object caching)
6. Content-Length
7. Content-Type: type of object

### Cookies

Cookies allow sites to keep teack of users and user settings. They have 4 components:
1. Cookie header line in HTTP request
2. Cookie header line in HTTP response
3. Cookie file on end system
4. Backend database on website

### Web Caching

A web-cache or proxy server is a network server that satisfies HTTP requests on the behalf of the origin server. It has its own storage and keeps copies of recently requested objects. There exists a web cache on both server and client.
This substantially reduces the response time (bottlenecks) and reduces traffic. 

Through the use of Content Distribution Networks, there are distributed caches localising traffic. 

Sometimes, objects in the cache may have gone stale. To verify if the objects are up to date, a conditional GET request is sent. This request uses the GET method and includes an If-Modified-Since field. 

## Domain Name System

Hosts can be identified either by their hostnames or IP addresses. 
The Domain Name System (DNS) translates the hostname into an IP address. It takes the help of two components
1. Distributed Database
2. Application Layer Protocol to query the database

DNS, however, adds an additional delay for the lookup of IP addresses. Usually, the cache contains the desired IP address in a nearby DNS server to reduce server traffic.

### Services Provided

The DNS provides:

1. Host Aliasing: A host with a complicated hostname can have more than one alias. The canonical hostname is used as the ground truth.
2. Mail Server Aliasing: For email addresses
3. Load Distribution: Among replicated servers, where a set of canonicals are associated with each server to reduce traffic (rotating IP).
   
The DNS is an app layer protocol because 
1. It relies on the underlying end-to-end transport layer protocol to transfer DNS messages
2. Runs between communicating end systems

All DNS queries are sent via UDP to port 53.

Usually centralised DNS servers are not used because
1. Single point of failure
2. High traffic volume
3. Distant centralised database
4. High maintenance
5. No scalability

In the distributed architecture, the DNS servers are organised in a heirarchy.
1. There are 13 root DNS servers, which contain the IP addresses of the top level domain (TLD) servers
2. The TLD servers contain the domains such as .com, .edu, etc
3. The Authoritative DNS servers are the servers on access by organisation.
   
The Local DNS server does not belong to the heirarchy, but accepts the initial DNS query and acts as a proxy, forwarding the query into the DNS server heirarchy only if the relative mapping is not already found in the Local DNS server's memory.

There are two ways of performing a lookup into the DNS heirarchy.
1. Iterative

    Host -> Local DNS -> Root -> Local DNS -> TLD -> Local DNS -> Authoritative -> Local DNS -> Host
    
    If the entry is already in the local DNS, then it is returned there itself.

2. Recursive

    Host -> Local DNS -> Root -> TLD -> Authoritative
    
    This recurses back in the same manner to the host.

In DNS caching, for a query chain, when the DNS server receives a DNS reply, it can cache the mapping in memory, by using this local DNS server and bypass the root DNS.

The DNS servers store Resource Records (RR) that store the mapping of hostname to IP address. This is a 4 tuple consisting of (Name, Value, Type, TTL).

The different types that RRs can hold are:
1. A : Name = hostname, Value = IP
2. NS : Name = domain, Value = hostname of authoritative DNS
3. CNAME : Name = alias hostname, Value = canonical hostname
4. MX : Name = alias hostname, Value = canonical mail server name

The DNS Message fields are
1. Header Section (12 bytes)
   1. 16 bit query ID 
   2. 16 bit flag field
   3. 16 bit Number of Questions
   4. 16 bit Number of Answer RRs
   5. 16 bit Number of Authoritative RRs
   6. 16 bit Number of Additional RRs
2. 32 bit Questions field : Name, type fields for query
3. 32 bit Answers field : RRs in response to query
4. 32 bit Authority field : RRs for authoritative server
5. 32 bit Additional Information

The nslookup program allows to send DNS queries to any DNS server.

To add RRs to the DNS,
1. Register domain name at registrar to check for uniqueness
2. Provide names and IP addresses of primary/secondary authoritative DNS servers
3. Ensure Type A and Type MX records are present
   
## Socket Programming

There are two types of network applications
1. Operation specified in protocol standard
2. Proprietary network application

### UDP Sockets

In UDP sockets, 
1. Attach destination address to packet
2. After packet passes sender's socket, the packet is routed to destination
3. Packet received by receiver socket

When a socket is created, it's port number identifies the application using it.

UDP Server side
1. Create socket at a port x
2. Read UDP segment from server socket
3. Write reply to server socket specifying client address and port

UDP Client side
1. Create socket at port y
2. Create datagram with server IP and port x
3. Send datagram via client socket
4. Read datagram from client socket
5. Close client socket

AF_INET flag tells the network the kind of network layer protocol is used, and SOCK_DGRAM indicates the use of UDP, and SOCK_STREAM indicates the use of TCP.

### TCP Sockets

TCP architecture is pretty much the same as UDP, but in this case, there needs to be a 3-way handshake. 

TCP Server side
1. Create socket at port x
2. Wait for incoming request using .listen()
3. Accept incoming request with .accept()
4. Read request from server socket
5. Write reply to server socket
6. Close connection and go to 2

TCP Client Side
1. Create socket
2. Connect to server using .connect()
3. Send request to server
4. Read reply from server
5. Close socket

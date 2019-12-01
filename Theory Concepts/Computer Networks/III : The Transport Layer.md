# The Transport Layer

The transport layer provides a logical communication between application processes running on different hosts. Transport layer protocols are implemented in the end systems but not on the network routers.

## Relationship between the Transport and Network Layer

The application layer messages are converted into segments by breaking those messages into chunks and adding a transport layer header. Each segment is converted to a network layer segment, where each segment is encapsulated by a network layer packet and sent to a destination.

The transport layer provides a logical communication between processes running on hosts, whereas network layer proides logical communication between hosts. The efficiency in delay and bandwidth of a transport layer is governed by the network layer. 

Certain services can be offered by the transport layer even when the underlying network layer does not offer it, the main being reliable data transfer and encryption.

## Overview of the Transport Layer in the Internet

The User Datagram Protocol (UDP) provides unreliable, connectionless data transfer whereas the Transmission Control Protocol (TCP) provides a reliable, connection oriented data transfer.

The Internet Protocol (IP) provides a best-effort delivery service to provide logical communication between hosts. Extending host-host delivery to process-process delivery is called transport layer multiplexing and demultiplexing.

UDP provides process to process delivery and error checking, but no guarantee on the data integrity. TCP provides reliable data transfer, with packet integrity using flow control and congestion control, but is necessarily more complex to implement.

## Multiplexing and Demultiplexing

Sockets facilitate the service of the transport layer. The job of delivering the data to the right socket is called demultiplexing and the job of gathering data chunks from hosts, encapsulating them with headers and passing the segment to the network layer is multiplexing.

The unique identifiers for socket-to-socket communication are the source and destination port addresses attached to the segment, which are each 16 bits long. 

### Connectionless Multiplexing and Demultiplexing

In connectionless multiplexing and demultiplexing, 
1. When a UDP socket is created, the transport layer automatically assigns a port number to the process.
2. The transport layer assigns the application data, source port, destination port and sends it as a segment to the network layer. 
   
A UDP socket is fully identified by a destination IP and destination port number. Source port is attached as a return address for the packets sent.

### Connection-Oriented Multiplexing and Demultiplexing

A TCP socket is identified by a source IP, source port, destination IP and destination port, to support simultaenous TCP sockets.

## Connectionless Transport : UDP

UDP is chosen over TCP in some cases:
1. Finer application level control over what data is sent and when.
   1. When applications can tolerate data loss and unreliability
2. No connectionless establishment
   1. No delay to establish connection
3. No connection state
   1. Maintains no buffers based on state
4. Small packet header overhead
   1. Only 8 bytes of overhead as opposed to 20 bytes in TCP

Lack of congestion control results in high loss rates when we speak in terms of streaming data, which is a major drawback in UDP.

### UDP Header

A UDP segment has the following structure:
1. 16 bit source port number
2. 16 bit destination port number
3. 16 bit length
4. 16 bit checksum
5. 32 bit application data

### UDP Checksum

The checksum is used to determine if bits in the UDP segment have been altered. This is done by performing 1s complement on the sum of all 16 bit numbers. The receiver adds all the words, including the checksum. If the answer is not all 1s, there are packets which are lost, but UDP does not provide any correction.

A checksum is required as
1. No guarantee that all links provide error checking
2. Bit errors can occur in router memory

## Principles of Reliable Data Transfer

The problem that reliable data transfer tries to solve is that the underlying network protocol is unreliable. Therefore, it lists the following types.

### Reliable data transfer over a perfectly reliable channel (rdt 1.0)

1. Underlying channel is completely reliable
2. No feedback given
3. Just normally transmit and receive data

### Reliable data transfer over a channel with bit errors (rdt 2.0)

1. Bits may be corrupted, but all packets are received in order.
2. Retransmit data that was not correct through periodic acknowledgements (Automatic Repeat Requests - ARQ)
3. In ARQ, three additional protocol capabilities are considered
   1. Error detection
   2. Receiver feedback - positive ACKs and negative NAKs
   3. Retransmission
4. These are known as stop-n-wait protocols as they wait for acknowledgements to transmit the next packet.
5. If the ACK or NAK packets are corrupt
   1. Retransmit if gibberish
   2. Attach a checksum
   3. Resend the packet
   4. Add a 1 bit sequence number
   
We use the sequence number in this case, and the receiver only needs to check this sequence number to check if the packet is a retranmission.

### Reliable data transfer over a Lossy Channel with Bit Errors (rdt 3.0)

1. Packet loss is handled by introducing a timeout for the ACK and NAK packets.
2. Only an additional timeout field is added to rdt 2.0 for every wait.
3. Since sequence numbers alternate between 1 and 0, this protocol is usually known as an alternating-bit protocol.

### Pipelined Reliable Data Transfer Protocols

Sender utilisation is very less as the amount of time it spends waiting for an acknowledgement on an average in stop-n-wait is very high.

The sender utilisation is given by

U = (L / R) / (RTT + L/R)

Pipelining is done so that multiple packets can be sent per acknowledgement. But this approach has its own drawbacks
1. Range of sequence numbers increases
2. Sender and receiver sides may have to buffer more than one packet
3. Range of sequence numbers depends on the manner in which the protocol responds to lost, corrupted or timeout packets.

### Go-Back-N (GBN)

In the GBN protocol, the sender transmits multiple packets without waiting for an acknowledgement, but is allowed to have only N unacknowledged packets at any given time. N is referred to as the window size and GBN is itself called the sliding window protocol. A limit of N is used to ensure flow control during transmission.

The sequence number in GBN is the number of the oldest unacknowledged packet and the next sequence number is the smallest sequence number yet to be sent.

The GBN sender must respond to mainly 3 events
1. Invocation from above : Check if window is full
2. Receipt of ACK : Cumalative ACKs till n packets
3. Timeout : Send all packets that have not yet been acknowledged

All packets not in order are discarded by GBN. If a packet n is lost, n + 1 is not buffered, but n and n + 1 are retransmitted.
The advantage of this is the removal of buffers to store out of order packets.

The drawback of GBN is, when the window size and bandwidth delay are large, a single packet loss can result in the whole window's retransmission.

### Selective Repeat (SR)

In selective repeat, the sender only retransmits the erroneous packets, but has to send acknowledgements for each correctly received packet.
Out of order packets are buffered until any missing packets are received.

SR sender actions:
1. When data is received from the above layer, the sender checks the next available sequence number for the packet. If it is within the sender's window, the data is sent. Else, the data is buffered/returned to the upper layer for later retransmission.
2. Timers are used to protect against lost packets, and a time is assigned to each such packet.
3. If ACK is received, SR sender marks that packet as received. If the packet's sequence number is equal to the base sequence number, the window base is moved forward to the unacknowledged packet with the smallest sequence number. If there are untrasmitted packets in this window, these packets are retransmitted.

SR receiver actions:
1. Packet with sequence number in (base, base + N - 1) is correctly received : Selective ACK is sent. If the packet was not previously received, it is buffered. If the packet has sequence no. = base, then this packet along with continuous packets are delivered.
2. Packet wit sequence number in (base - N, base - 1) is correctly received : ACK is sent
3. Else, ignore packet.

## Connection-Oriented Transport : TCP

TCP is a stateless connection-oriented protocol in intermediate network elements. It is a full duplex protocol, allowing bidirectional data transfer and point-to-point, having only one sender and one receiver for a channel.

When a TCP connection has to be made, a three-way handshake occurs where the sender first sends a special segment, the receiver acknowledges this segment and on its receipt, the sender sends the payload.

When data is queued on the TCP send buffer, the maximum segment size (MSS) determines the amount of data to be grabbed and sent by this sender. The MSS is typically set by first determining the length of the largest link later frame that can be sent by the local sending host and ensuring the payload + header fit into a single frame. MSS is defined as the maximum amount of application layer data in the segment, not the size of the TCP segment.

### TCP Segment Structure

The TCP header has the following fields
1. 16 bit source port number
2. 16 bit destination port number
3. 32 bit sequence number
4. 32 bit acknowledgment field
5. 4 bit header length
6. 8 bit options field with flags
   1. ACK : Acknowledgement
   2. RST : Reset
   3. FIN : Finish
   4. SYN : Sync
   5. PSH : Push - Pass data to upper layer immediately
   6. URG : Urgent
7. 16 bit receive window
8. 16 bit checksum
9.  16 bit urgent data pointer

The acknowledgment number the host puts in the segment is the sequence number of the next byte the host expects from the sender. Because the acknowledgements only depend on the previous byte sent, they are called cumalative acknowledgements.

When packets are lost, the receiver buffer leaves gaps for these packets which saves network bandwidth.

The sequence numbers can be initialised at random, to avoid new packets being referenced to previous connection paradigms.

The transfer of acknowledgement with server to client data is known as piggybacking.

### Estimating RTT

The sample RTT for a segment is the amount of time between when a segment is sent and when the acknowledgement is received. The sample RTT is not recalculated again for retransmissions.

To handle fluctuations in the RTT due to congestion, a typical RTT is estimated by

EstimatedRTT = ( 1 - alpha ) * EstimatedRTT + alpha * SampleRTT where alpha is usually 0.125.

The variability in the RTT is measured by 

DevRTT = (1 - beta) * DevRTT + beta * | SampleRTT - EstimatedRTT|

The timeout interval must be estimated to be greater than or equal to the estimated RTT, but not too great so as to lead to transmission delays. 

TimeoutInterval = 4 * DevRTT + EstimatedRTT

When a timeout occurs, the value of this interval is doubled to avoid premature timeouts for a subsequent segment that will soon be acknowledged. 

### Reliable Data Transfer

Timer management also adds a significant overhead, so TCP uses only a single timer. 

To reduce longer timeout periods, duplicate acknowledgements are sent, where a segment sent is reackowledged. When gaps are detected, the reacknowledged segment is the last in-order byte received. If one segment is lost, there will be back-to-back duplicate ACKs. If the TCP sender receives 3 duplicate ACKs for the same data, that means the data following this segment has been lost.
TCP does a fast retransmit in this case, retransmitting the segment before that segment's timer expires.

Hence, TCP is a selective acknowledgement retransmitter, a hybrid of GBN and SR.

### Flow Control

Flow control is required to counteract data overflows in data received. TCP provides flow control by having the sender maintain a variable called receive window, which tells the sender how much space does a receiver's buffer have.

The last byte read is the number of the last byte in the data stream read from the buffer in the receiver. The last byte received is the number of the last byte in the datastream that has arrived from the network and has been placed in the receiver buffer. 

TCP checks if LastByteReceived - LastByteRead <= ReceiverBuffer

and

ReceiverWindow = ReceiverBuffer - [LastByteReceived - LastByteRead]

The current value of the receiver window is placed in the TCP receive window field.

On the receiver side, the window is maintained as

ReceiverWindow = ReceiverBuffer - [LastByteReceived - LastByteACKed]

When the window is empty, the receiver does not send anything, blocking the sender. This is countered by making the sender continously poll the receiver to check if the window is opened. 

UDP does not provide flow control.

### TCP Connection Management

1. Client side sends a special TCP segment with no app layer data. SYN bit is set to 1, and hence, this segment is called a SYN segment. The initial segment number is set randomly and encapsulated within an IP datagram.
2. At the server, the server extracts the TCP SYN and allocates the required buffers and variables to that connection, and sends a connection granted segment SYNACK, with SYN = 1 and ACK set to the next sequence number.
3. Upon SYNACK, the client allocates buffers and sends the payload with SYN = 0, abd the ACK field as the next sequence number.
4. When the connection is closed, a FIN bit is sent, and the server sends an ACK with the FIN bit set as well.
5. If a wrong port is requested, the RST bit is set and the connection has to reset.

### TCP Congestion Control

TCP uses end-to-end connection, since the IP layer provides no feedback to the end systems regarding congestion on the network. Each sender limits its rate of sending data as a function of perceived network congestion. If congestion is less, more data is sent, and vice versa.

TCP congestion control is operated at a sender where the sender keeps a congestion window variable cwnd and a receiver window variable rwnd, which constrain the rate of sending as

LastByteSent - LastByteReceived <= min {cwnd, rwnd}

The sender's rate is roughly cwnd / RTT bps. By adjusting the cwnd, the sender can adjust the rate at which it sends data to the connection. A loss event is defined either as a timeout or 3 duplicate acknowledgements received.

Because TCP uses acknowledgements to trigger its increase in congestion window size, it is known as a self-clocking protocol.

The following principles are maintained for congestion control
1. A lost segment implies congestion, hence, the TCP sender rate must decrease when a segment is lost
2. An acknowledged segment indicates the network is delivering the segments, so increase the sending rate
3. Bandwidth probing: Increase the rate of response to arriving ACKs until a loss event occurs, at which the rate decreases. It probes for a rate at which congestion onset begins, backs off from that rate and then probes again to see if congestion rate has been changed.

The TCP congestion control algorithm has 3 components
1. Slow Start
   1. Initialise the value of cwnd to a small value of 1 MSS
   2. Since the capacity of the link is high, the bandwidth will be found much faster
   3. Increase MSS by 1 everytime a transmitted segment is acknowledged
   4. If loss event occurs, set cwnd to 1 and start slow start again
   5. Another variable ssthresh is set to cwnd / 2, and if ssthresh = cwnd, slow start ends and TCP switches to congestion avoidance mode
   6. If 3 duplicate ACKs are encountered, a fast retransmit is performed and TCP goes into fast recovery
2. Congestion Avoidance
   1. Increase cwnd by MSS till timeout occurs or triple ACKs occur
   2. Record ssthresh to half of cwnd and switch to fast recovery
3. Fast Recovery
   1. Increase cwnd by 1 MSS for every duplicate ACK received for the missing segment
   2. When ACK arrives for received segment, TCP goes into congestion avoidance by deflating cwnd.
   3. If timeout occurs, go to slow start.


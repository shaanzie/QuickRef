# The Link Layer

## Introduction

There are two fundamentally different types of link-layer channels

1. Broadcast Channels 
    
    These connect multiple hosts in wireless LANs, satellite networks and HFC networks. A medium access protocol is needed to coordinate frame transmission. This can be a central controller, or the hosts can themselves be used to coordinate transmissions.

2. Point-to-Point Communication Links

    Often found between long-range routers, or between ethernet switches and end systems. This usually uses the PPP.


Node: Any device that runs a link-layer protocol
Links: Communication channels that connect adjacent nodes

In order for a datagram to be transferred, it must move over individual links in the end-to-end path.
Over a given link, a transmitting node encapsulates the datagram in a link-layer frame and transmits the frame onto the link.

### Services of the Link Layer

The main services provided by the Link Layer are:

1. Framing

    Network layer datagrams are encapsulated within a link-layer frame before transmission over the link. The frame consists of a data field, in which the network-layer datagram is inserted, and a number of header fields. The structure of the frame is defined by the protocol.

2. Link access

    A medium access control (MAC) protocol specifies the rules by which a frame is transmitted onto a link. The protocol says that the sender can send a frame whenever the link is idle. A multiple access problem occurs when multiple nodes share a single broadcast link. Here, the MAC protocol serves to coordinate the frame transmissions of the many nodes.

3. Reliable delivery

    Guarantees movement of each network layer datagram across the link without error. This is achieved through acknowledgements and retransmissions. This is usually used for links which have high error rates, with the goal of correcting the error locally, rather than force end-to-end retransmission. However, this may be considered an uncessary overhead for low bit-error links.

4. Error Detection and correction
   
    Bit errors introduced by signal attenuation and electromagnetic noise can be detected by the link layer by having the transmitted node contain error detection bits in the frame.

### Implementation of the Link Layer

The link layer is mainly implemented in a network adapter, also usually called a network interface card (NIC). 
The link layer controller resides in the centre of this adapter, which is a single, special-purpose chip that implements the services of the link layer.

On the sending side, the controller takes a datagram that has been created and stored in host memory by the higher layers of the protocol stack and encapsulates the data in a link layer frame, and then transmits the frame on the communcation link, following the link access protocol.

On the receiving side, the controller recieves the entire frame, and extracts the network layer datagram.

If the link layer performs error detection, the sending controller sets the error detection bits in the frame header and the receiver performs the error detection.

The software of the link layer implements functionality such as assembling link layer addressing information and activating the controller hardware. On the receiver side, the link layer software responds to controller interrupts, handling error conditions and passage of datagrams to the upper network layer.

## Error Detection and Correction

The data needed to be protected includes not only the datagram passed down from the network layer for transmission, but also the link layer adressing information, sequence numbers and so on. 
Complex error detection techniques, however, incur a large overhead, and more computation is required to compute and transmit a large number of error detection and correction bits.

### Parity checks

The simplest form of checking is using a single parity bit. The sender simply includes one additional bit and chooses its value such that the total number of 1s in the d + 1 received bits is even. This can be implemented for odd parity as well.

Receiver operation is also very simple, as the receiver only had to count the number of 1 bits in the received d + 1 bits. 

This incurs a problem when even number of bit errors occur, which would go undetected in this scenario. This is acceptable only when the probability of bit errors is small and errors occur independently from one bit to the next. But these errors are often clustered together in bursts, and the probability of undetected erorrs in a frame protected by a single bit parity is high.

We can use a two dimensional parity for row-and-column arranged data, which allows the column and row with the erroneous bit to be detected, and can provide a mechanism to correct it as it knows where the error has occured for single bit errors.

Two dimensional parity can detect, but not correct, a combination of two errors in a packet. 

The ability of the receiver to detect and correct errors is known as forward error correction (FEC). FEC can be standalone or used with ARQ. They are valuable as they can decrease the number of sender transmissions required. most importantly, they allow for immediate correction of errors at the receiver, avoiding round trip propogation delay for the sender to receive a NAK packet and for the retransmitted packet to propogate to the receiver.

### Checksum

In checksums, the data is treated as a sequence of k-bit integers. The simplest check is to sum these k-bit integers and use the sum as the error-detection bits. The internet checksum is based on this approach, where data is treated as 16-bit integers and summed. The 1s complement forms the checksum that is carried in the segment header. The receiver takes the 1s complement of the sum of the received data and checks whether the result is all 1 bits.

Checksums require relatively little packet overhead. But they provide weak protection compared to cyclic redundancy checks.

Checksumming is used in the transport layer and cyclic redundancy in the link layer because the transport layer is implemented at a software level as a part of the OS, which requires a simple and fast error detection scheme. Since there is dedicated hardware in the link layer, these complex CRC operations can be performed.

### Cyclic Redundancy Check (CRC)

CRC codes or Polynomial codes view bit strings to be sent as polynomials whose coefficients are 0 or 1 in the bit string, with the operations on the bit string to be viewed as polynomial arithmetic.

The sender and receiver first agree upon a r + 1 bit pattern, called the generator (G). The MSB of G is 1. For data D, the sender chooses r additional bits, R, and append them to D such that the resulting d + r bit number is a multiple of G using modulo 2 arithmetic. 

We find R such that there is an n such that

D * (2^r) XOR R = nG

Which gives R as

R = remainder ( ( D * (2 ^ r)) / G)

## Multiple Access Links and Protocols

A point to point link consists of a single sender and a single receiver at the two ends of a link. Many link layer protocols have been designed for point-to-point links, such as the PPP and high-level data link control (HDLC). 

The broadcast link can have several sending and receiving nodes all connected to the same, single, shared broadcast channel. When a node transmits a frame over broadcast, each node subscribed to the boradcast receives a copy.

The main issue arises when we deal with coordination of multiple receivers and senders on a shared broadcast channel - the multiple access problem. 

With multiple access protocols, nodes regulate their transmission onto a shared broadcast channel. Because all nodes are capable of sending and transmitting at the same time, all of the nodes can receive multiple frames at a time, where, all the transmitted frames collide at all the receivers. This causes intricacies that the nodes cannot untangle, and all these frames are lost, and the broadcast channel is wasted during the collision interval. 

Multiple Access Protocols can belong to one of these categories
1. Channel partitioning protocols
2. Random access protocols
3. Taking-turns protocols

Each multiple access protocol needs to have the following characteristics
1. When only one node has data to send, that node has a throughput of the rate of the broadcast channel.
2. When M nodes have data to send, each node has a throughput of R/M bps on an average.
3. The protocol is decentralised.
4. The protocol is simple and easy to implement.


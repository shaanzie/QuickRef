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


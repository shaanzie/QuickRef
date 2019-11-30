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


The main services provided by the Link Layer are:

1. Framing

    Network layer datagrams are encapsulated within a link-layer frame before transmission over the link. The frame consists of a data field, in which the network-layer datagram is inserted, and a number of header fields. The structure of the frame is defined by the protocol.

2. Link access

    A medium access control (MAC) protocol specifies the rules by which a frame is transmitted onto a link. The protocol says that the sender can send a frame whenever the link is idle. A multiple access problem occurs when multiple nodes share a single broadcast link. Here, the MAC protocol serves to coordinate the frame transmissions of the many nodes.
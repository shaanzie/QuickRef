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

### Channel Partitioning Protocols

Time Division Multiplexing and Frequency Division Multiplexing are two techniques that can be used to partition a broadcast channel's bandwidth among all nodes sharing the channel. 

#### Time Division Multiplexing

TDM divides the channel into time frames and further divides each frame into time slots. Each time slot is then assigned to one of the N nodes. Whenever a node has a packet to send, it transmits the packet's bits during its assigned time slot in the revolving TDM frame. Slot sizes are chosen such that a single packet can be transmitted in a slot time.

#### Frequency Division Multiplexing

FDM divides the R bps channel into different frequencies (each with a bandwidth of R/N bps) and assigns each frequency to one of the N nodes. It thus creates N smaller channels transmitting at R/N bps out of the single R bps channel. It shares the same drawbacks and advantages of TDM.

TDM and FDM are appealing because
1. It eliminates collision
2. It is perfectly fair

Each node gets a dedicated R/N bps during each time frame.

Drawbacks of TDM and FDM are
1. A node is limited to an average rate of R/N bps even if its the only node sending data.
2. A node must always wait for its turn in the transmission sequence, even if its the only node sending data.

#### Code Division Multiple Access

CDMA assigns a different code to each node. Each node then uses its unique code to encode the data bits it sends. If the coding is done properly, different nodes can transmit simultaenously and yet receive the correct data, in spite of interfering transmissions.

### Random Access Protocols

In a random access protocol, a transmitting node always transmits at the full rate of the channel. When there is a collision, the node involved in the collision repeatedly retransmits its frame until the frame gets through without a collision.

The retranmission during collision occurs after a delay, with the delay period being random, which allows nodes to pick a delay that is sufficiently less than the delays of the other colliding nodes, and can sneak its frame into the channel without collision. 

#### Slotted ALOHA

##### Key assumptions

1. All frames consist of exactly L bits
2. Time is divided into slots of size L/R seconds 
3. Nodes start to transmit frames only at the beginning of the slots
4. The nodes are synchronized so that each nodes knows when the slots begin
5. If two or more frames collide in a slot, then all the nodes detect the collision event before the slot ends

##### Operation

1. When a node has a fresh frame to send, it waits until the beginning of the next slot and transmits the entire frame in the slot.
2. If there isnt a collision, the node has successfully transmitted its frame and does not retransmit.
3. If there is a collision, the node detects the collision before the end of the slot. The node retransmits its frame in each subsequent slot with some probability p until the frame is transmitted without collision. (All the nodes calculate p independently).

##### Advantages

1. Allows a node to constantly transmit at full rate, when the node is the only active node.
2. Highly decentralized, as each node independently decides whether to retransmit or not
3. It is extremely simple

##### Efficiency concerns

1. When there are multiple active nodes, a certain fraction of the slots will have collisions and will therefore, be wasted.
2. Another fraction of the slots would be empty, because all the active nodes would refrain from transmitting.

A slot in which exactly one node transmits is said to be a successful slot.
The efficiency of a slotted multiple access protocol is defined to be the long-run fraction of successful slots when the number of active nodes is large, and each having a large number of frames to send.

##### Deriving maximum efficiency

Assumptions: 
1. Each node always has a frame to transmit with a probability p per slot.
2. There are N nodes in the network.

Probability that a given slot is successful = Probability that one of the nodes transmits and N - 1 nodes do not transmit.

Probability that a node transmits = p
Probability that N - 1 nodes don't transmit = ( 1 - p ) ^ ( N - 1 )

Probability a given node has success is p(1-p)^(N-1).

Because there are N nodes, the probability that any one of the N nodes has a success is N * p * (1 - p) ^ (N - 1)

To obtain the maximum efficiency for N active nodes, we have to find p* that maximises this expression. For this, the limits are taken on Np*(1-p*)^(N-1) as N approaches infinity. The maximum efficiency of the protocol is given by 1/e = 0.37. That is, the effective channel bandwidth is only 0.37 R bps, which is not very efficient.

#### ALOHA (Unslotted)

In pure ALOHA, when a frame first arrives, the node immediately transmits the frame in its entirety to the broadcast channel. If a transmitted frame experiences collision with one or more other transmissions, the node will then immediately retransmits with probability p. Otherwise, the node waits for a frame transmission time. After this wait, it then retransmits the frame with probability p, or waits for another frame time with probability 1-p.

##### Deriving maximum efficiency

The same assumptions as slotted ALOHA are made here and take the frame transmission time as the unit of time.

Suppose a node begins transmission at a time t. In order for transmission to be successful, no other nodes can begin transmission in (t - 1, t).
The probability that no node transmits in that time is (1 - p)^(N-1). Similarly, no node can begin tranmsmission when node i is transmitting. 
This probability is (1-p)^(N-1). 
So the probability that a given node has successful transmission is p(1-p)^(2 * (N - 1)).

This gives an efficiency of 1/2e, half of that of slotted ALOHA.

#### Carrier Sense Multiple Access (CSMA) and CSMA with collision detection(CSMA/CD)

The two main ideas that CSMA and CSMA/CD build upon are
1. Carrier sensing - listen to a channel before transmitting and transmit when no other transmissions occur
2. Collision detection - if interference occurs, the node stops transmitting and waits a random amount of time before repeating the sense-and-retransmit.

The operation of an adapter in a node attatched to a broadcast channel is summarized as
1. Obtain datagram from network layer, prepare link layer frame and put the frame adapter buffer.
2. If channel is idle, start to transmit the frame. If not, wait till no signal energy is observed.
3. While transmitting, monitor the presence of signal energy from other adapters on the channel.
4. If no signal energy is observed, finish transmit. If signal energy is detected, abort the transmission.
5. Wait for random amount of time after abort, then return to step 2.

The time for wait is random because if the time was fixed, the collision would happen again after the fixed time. 

Tradeoffs to choose the random interval
1. If the interval is large and the number of colliding nodes are small, nodes have to wait a large amount of time before repeating sense-and-transmit-when-idle.
2. If the interval is small and the number of colliding nodes are large, the random values might be close or same, causing collisions again.

The requirement thus is to have an interval that is short when number of collisions is small, and large when number of collisions is large.

The binary exponential backoff algorithm used in Ethernet and DOCSIS solves this.

In binary exponential backoff, the node chooses a value of K at random from 0 to 2 ^ (n - 1) where n is the number of colliding nodes. 
This allows the interval to be large when collisions are large and small when the collisions are small.

##### Efficiency

When only one node is transmitting, the full bandwidth of the channel is used. When there are multiple nodes, however, the channel efficiency decreases. A closed form approximation for the efficiency is,
Let prop_d denote the maximum time it takes signal energy to propogate between two adapters.
Let trans_d denote the time to transmit a maximum size frame.

Then, efficiency is given by 1 / ( 1 + (5*prop_d) / trans_d).

### Taking-turns protocols

These protocols were made because the previous ones did not guarantee a transmission rate of R/M bps for M simultaenousy transmitting nodes.

#### Polling protocol

The polling protocol requires one of the nodes to be the master node. The master node polls each of the nodes in a round robin fashion. Each node being polled by the master can send some amount of frames. This eliminates collisions and empty slots, and achieves a higher efficiency. 

Drawbacks:
1. Introduces polling delay, the time to notify a node that it can transmit.
2. If master node fails, entire channel becomes inoperative.

#### Token Passing protocol

In this, there is no master node. A special purpose frame called a token is exchanged among nodes in a fixed order. When a node receives a token, it holds onto the token only if it has some frames to transmit when it receives the token, otherwise it forwards the token to the next node.

Drawbacks:
1. Failure of one node can crash the channel.
2. If a node does not release the token, recovery options need to be invoked to get the token back.

### DOCSIS : Link Layer Protocol for Cable Internet Access

The Data-Over-Cable Service Interface Specifications (DOCSIS) specifies the cable data network architecture and its protocols. DOCSIS uses FDM to divide the downstream (CMTS to modem) and upstream (modem to CMTS) network segments into multiple frequency channels.

Frames transmitted on the downstream channel by the CMTS are received by all cable models receiving that channel, since there is just a single CMTS transmitting on the downstream channel. There is no multiple access problem there.
On the upstream channel however, multipl32 cable modems share the same upstream channel frequency to the CMTS, which can cause collisions.

Each upstream channel is divided into intervals of time, each containing a sequence of mini slots during which the cable modems can transmit to the CMTS. The CMTS explicitly grants permissions to individual modems to transmit during specific mini-slots. The CMTS accomplishes this by sending a control message called MAP on a downstream channel to specify which cable modem can transmit during which mini-slot for the interval of time specified in the control message. CMTS hence, can assure that no colliding transmissions occur during a mini slot.

The CMTS knows which cable modems have data to send by having cable modems send mini-slot request frames to the CMTS during a special set of mini-slots alloted. These mini-slot-request frames are transmitted at random and so may collide with each other. The cable modem infers that its mini-slot-request frame experienced a collision if it did not receive a response to the requested allocation in the next downstream control message. When collision is encountered, binary exponential backoff is used to defer the retransmission of its mini-slot-request frame to a future time slot. When there is less traffic, this retransmission occurs nominally.

## Switched Local Area Networks

### Link Layer Adressing and ARP

The network interfaces at each host and router have a seperate link layer address associated with them. So a host or a router can have multiple link layer addresses, but link layer switches do not have link layer addresses associated with them. The link layer address is called a LAN address, a physical address or a MAC address. 

No two adapters have the same MAC address. 

An adapter's MAC address has a flat structure and does not change based on the location of the adapter. 

When a frame needs to be sent to some destination adapter, the sending adapter inserts the destination adapter's MAC address into the frame and sends the frame into the LAN. The adapter may receive frames not addressed to it, so it checks whether its MAC address matches the one in the frame. 

When data needs to be sent to all the network devices on a network, it is sent with a special MAC broadcast address in the destination address field, and is usually a string of 48 consecutive 1s. (FF-FF-FF-FF-FF-FF)

The Address Resolution Protocol (ARP) translates network layer addresses to link layer addresses. An ARP module in the sending host takes any IP address on the same LAN as input and returns the corresponding MAC address. It is similar to the DNS, but the key difference is that DNS resolves host names for hosts anywhere on the net, but ARP resolves host addresses only for interfaces on the same subnet. 

Each host and a router has an ARP table in its memory, which contains mappings of IP addresses to MAC addresses. It also contains the TTL value which indicates when this mapping will be deleted.

To fill the entries of the ARP table, the sender constructs a special ARP packet, whihc has several fields, including the sending and receiving IP and MAC addresses. Both the query and response have the same format, and this packet queries all the hosts and routers on the subnet to determine their IP addresses.

Features of the ARP:
1. Query ARP message is sent within a broadcast frame, whereas the response is sent through a standard frame. 
2. ARP is plug-and-play, and does not need to be configured by a system admin.
3. If a host disconnects from a subnet, the ARP entry also gets deleted.

To send data accross subnets, the routers also have ARP tables, and the number of ARP modules depend on the number of interfaces the router is connected to. 

### Ethernet

#### Why Ethernet succeeded
1. First widelty deployed high-speed LAN.
2. Token ring, FDDI, ATM, etc were more complex and expensive
3. Higher data rate, with the advent of switched Ethernet
4. Hardware cheap and readily available

A hub is a physical layer device that acts on individual bits rather than frames. LANs were switched to Ethernet installations using these hubs in a star topology. A hub simply recreates an arriving bit, boosts its energy strength, and transmits the bit onto other interfaces. Later, hubs were replaced with switches.

#### Frame Structure

1. Data field (46 - 1500 bytes) 

    Field carries the IP datagram. The MTU of Ethernet is 1500 bytes, and the minimum size is 46 bytes, which means that if an IP datagram size is lesser than 46 bytes, it will be stuffed to fill out the 46 bytes. The network layer uses the length field in the IP datagram header to remove the stuffing.

2. Destination address (6 bytes)

    MAC address of the destination adapter. 

3. Source address (6 bytes)

    MAC address of the source adapter.

4. Type field (2 bytes)

    Permits ethernet to multiplex network-layer protocols. Since different network layer protocols can be used, it should know which protocol is the one used in that specific datagram transfer.

5. Cyclic Redundancy Check (4 bytes)

    Detect bit errors.

6. Preamble (8 bytes)

    Each of the first 7 bytes of the preamble has a value 10101010, and the last byte is 10101011. This is to wake up the receiving adapters and to synchronize the clocks to the sender's clock. This is required to negate the effects of drifts that occur on the network.


Ethernet provides an unreliable service to the network layer, as it does not acknowledge the result of the CRC check. When the frame fails the CRC check, it simply discards that frame, and the sending adapter has no idea whether the transmitted frame has reached the destination or not. This gap in data is handled by the upper Transport Layer protcols and not by the Ethernet.

A repeater is a physical layer device that receives a signal on the input side and regenerates the signal on the output side, to increase the range of Ethernet.

The Gigabit Ethernet is an extension to the highly successful 10 Mbps and 100 Mpbs Ethernet standards. It's key features are:
1. Uses the standard Ethernet frame format
2. Allows for point-to-point links as well as shared broadcast channels
3. Uses CSMA/CD for shared broadcast (distance restricted for acceptable efficiency)
4. Allows full duplex operation at 1000 Mbps for P2P channels.

###  Link Layer Switches

The role of a switch is to receive incoming link layer frames and forward them to outgoing links. The switch is transparent to the hosts and routers in the subnet. Switch output interfaces have buffers to allow frames to be stored if the capacity of the link is being exceeded.

#### Forwarding and Filtering

Filtering is the switch function that determines whether a frame should be forwarded or dropped. Forwarding is the function that determines the interfaces to which a frame should be directed, and then move the frame to those interfaces. Switch filtering and forwarding are done with a switch table. An entry in the switch table contains the MAC address, the switch interface and the time at which the entry was placed into the table.

For a given destination address D of a frame arriving at a switch at interface x, there can be 3 possibilities
1. There is no entry for D. In this case, the switch forward copies of the frames to the output buffers preceding all interfaces except x. (Broadcast)
2. There is an entry for D, associating D with x. Perform filtering by dropping this frame.
3. There is an entry for D, associating D with y. Perform forwarding to output buffer of y.

#### Self Learning
The table of a switch is built automatically, dynamically and autonomously. This is accomplished as:
1. The switch table is initially empty.
2. For each incoming frame received, the switch stores in its table the MAC address from the source address field, the interface from which the frame is arriving and the current time. 
3. The switch deletes an address in the table if no frames are received from that address after some period of time, called the aging time.

Switches are plug-and-play devices for this reason.

#### Properties of Link Layer Switching

1. Elimination of collisions 
   1. No wasted bandwidth
   2. Switches buffer frames and never transmit more than one frame segment at a time
   3. Maximum aggregate throughput is the sum of all the switch interface rates
   4. Significant performance improvement over LANs with broadcast links
2. Heterogenous links
   1. Isolation of links from one another
   2. Allows LAN to operate at different speeds over different media
3. Management
   1. Eases network management
   2. Cuts non-working hosts off the network

#### Switches vs Routers

Router is a layer-3 packet switch, whereas a switch is a layer-2 packet switch.

Pros of switches:
1. Plug-and-play
2. High filtering and forwarding rates

Cons of switches:
1. To prevent cycling of broadcast frames, the active topology of a switch is restricted to a spanning tree.
2. Requires large ARP tables for large switched networks and generates a lot of ARP traffic and processing
3. Susceptible to broadcast storms - if one host transmits endlessly, network will collapse.


Pros of routers:
1. No cycles through routers as addressing is heirarchical, can only cycle when misconfigured
2. Can support mutiple topologies
3. More robust isolation of traffic 

Cons of routers:
1. Not plug-and-play
2. Larger per-packet processing

### Virtual Local Area Networks

#### Drawbacks of switched LANs
1. Lack of traffic isolation
   1. Frames whose destinations are not yet self-learned need to traverse through the whole institutional network.
2. Inefficient use of switches
3. Managing users

#### VLAN Usage

A switch that supports Virtual Local Area Networks allows multiple virtual LANs to be defined over a single physical LAN infrastructure. Hosts within a VLAN can communicate with each other as if they are connected to the same switch. 

In a port based VLAN, the switch's interfaces are divided into groups, where each group constitutes a VLAN, with the ports in each VLAN forming a broadcast domain. 

Two VLANs can communicate with a VLAN switch port connected to an external router and configuring that port to belong to both the VLANs.

For more such networks, this option is not scalable. So VLAN switches are interconnected, called VLAN trunking. A special port on each VLAN switch is configured as a trunk port to interconnect the two VLAN switches. The trunk port belongs to all VLANs, and frames sent to any VLAN are forwarded over the trunk link to the other switch. The VLAN tag specifies the origin of the frame. 



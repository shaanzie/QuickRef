# Introduction to Computer Networks

## What is the Internet?

The Internet is a network that interconnects end systems together. These end systems are analogously called hosts. End systems are connected together by a network of communication links and packet switches. 

The transmission rate of a link is represented in bps, or bits per second. Packages of information are sent via these links, and these packages are called packets. 

A packet switch takes a packet arriving on one of the incoming communication interfaces and forwards it on one of its outgoing communication links. There are mainly two types of packet switches: routers and link layer switches. Link layer switches are usually used in access networks, while routers are typically used in the network core.

A sequence of communication links that a packet takes is called a route or a path. 

End systems access the internet through Internet Service Providers (ISPs).

End systems, packet switches, and other pieces of the Internet run protocols that control the sending and receiving of information within the Internet. The Transmission Control Protocol (TCP) and Internet Protocol (IP) are the two most important ones on the Internet. The IP protocol specifies the format of the packets that are sent and received among routers and end systems.

Internet standards are developed by the Internet Engineering Task Force (IETF) and the IETF standard documents are called requests for comments (RFCs), and define the protocols used in the internet.

In a service point of view, the internet can be defined as an infrastructure that provides services to applications, such as VoIP, web surfing, etc. These applications are said to be distributed, as they involve multiple end systems exchanging data with each other.

End systems attatched to the internet provide an Application Programming Interface (API) that specifies how a program running on an end system asks the internet infrastructure to deliver data to a destination program. The internet API is a set of rules that the sending program must follow to deliver data.

A protocol defines the format and the order of messages exchanged between two or more communicating entities and also the actions taken on the transmission/receipt of a message or an event.

## The Network Edge

Hosts are often divided into clients and servers, where servers store and distribute information to a bunch of clients.

An access network is defined as a network that physically connects an end system to the first router (edge router) on a path from the end system to any other distant end system.

The most prominent types of broadband residential access are digital subscriber line (DSL) and cable.

### Digital Subscriber Line

In a DSL, a digital subscriber line modem uses the existing telephone line to exchange data with a DSL Access Multiplexer (DSLAM), located in a central office (CO). The home's DSL modem takes digital data and translates to high frequency tones from transmission over telephone lines to the CO.

The signals have different frequencies, which allow a telephone call and internet to be accessible at the same time. On the customer side, a splitter seperates the data and telephone signals arriving.

The downstream and upstream rates are different in a DSL, and hence are said to be asymmetric. DSL was designed for short distances between the homes and CO, where if its greater, users must look for alternative ways to connect to the internet.

### Cable

Cable internet access makes use of the cable television company's infrastructure. Fibre optics connect the cable head end to a neighourhood level junction, from which coaxial cables reach homes. Since both fibre optic cables and coaxial cables are used, it is called a Hybrid fiber coax (HFC) connection.

Cable internet access requires cable modems, which connect PCs via an ethernet port. 

At the cable head end, the cable modem termination system (CMTS) serves a similar function to the DSLAM, turning analog from homes to digital signals. 

Cable internet access is a shared medium, where every packet sent goes to every link and every packet sent by a home travels to the head, which can alter the bandwidth.

The FTTH (Fiber to the Home) concept provides optical fiber path from the CO to the home. Direct fiber is one fiber leaving the CO for each home, and each fiber is split after getting relatively close to the homes to service multiple homes. 

Splitting can be done through Active Optical Networks (AONs), which is switched ethernet, or via Passive Optical Networks (PONs).

Each home in a PON has an optical network terminator (ONT), which is connected to a neighbourhood via a dedicated fiber cable. The splitter combines a number of homes into a single, shared optical fiber, which connects to an optical line terminator (OLT) in the CO. The OLT provides conversion from optical to electrical and connects to the internet via the telco's router. In the home, a router is connected to the ONT to provide internet.

### Access in the Enterprise

Corporate and campuses usually use LANs and Ethernet.

In Ethernet, a twisted copper wire is connected to an ethernet switch and a network of such switches connects to the internet.

In wireless LAN, or WiFi, users transmit/receive packets to/from an access point that is connected to an enterprise network. 

### Physical Media

Physical media allow the transmission of bits as electromagnetic waves accross transmitters and receivers. 

In guided media transmission, the waves are guided through solid media such as wires. In unguided media, waves propogate through the atmosphere. 

A twisted pair copper wire has two insulated copper wires arranged in a spiral. The wires are twisted to reduce interference from the same wires. Unshielded twisted pair wires (UTP) are commonly used for computer networks within a building.

Coaxial cables consist of two copper conductors, the two conductors being concentric. They can be used as a shared medium, where a number of end systems can be connected directly to the cable. 

Optical fibre is a thin, flexible medium that conducts pulses of light.

Radio channels carry signals through EM spectrum waves and are wireless. Environmental conditions determine path loss, shadow fading (obstructions), multi-path fading (signal reflection) and interference.

A communication satellite links two or more earth-based microwave transmitters/receivers using different frequencies at each hop. 

Geostationary satellites permanently remain above one spot to transmit data.

Low earth orbiting satellites (LEOs) are placed closer to the earth and revolve. 

## Network Core

In the network core, end systems exchange messages with each other. 

### Packet Switching

A message is broken down into small chunks called packets and each packet travels through communication links and packet switches. Packets are transmitted at a rate equal to the full transmission rate of the link.

Therefore, a packet of size L bits will take L/R seconds to transmit over a link of R bps.

Most packet switches use store-and-forward mechanisms, where a packet switch must receive the entire packet before transmission of the outbound packet. Each packet switch has multiple links to it. 

For each link, the packet switch has an output buffer that stores the packets the router is about to send. If the link is busy, the packet waits in the output buffer, causing a queueing delay. Since the buffer size is finite, if the buffer is full, an arriving packet will be dropped, causing packet loss. 

Each router has a forwarding table that maps the destination addresses to the routers outbound links. When a packet arrives at the router, the router examines its address and searches the table for the destination IP. 

### Circuit Switching

In circuit switching networks, resources needed along a path are reserved for the duration of communication between the end systems. Communication happens at a guaranteed transfer rate.

A circuit in a link is implemented either as frequency division multiplexing (FDM) or time division multiplexing (TDM). 

In FDM, the frequency spectrum of a link is divided among the connections established across the link.
In TDM, the time is divided into frames of fixed duration, and each frame into time slots. When connections are established, the network dedicates one time slot in every frame to this connection.

For TDM, the transmission rate of a circuit = Frame rate * number of bits in a slot.

Circuit switching is wasteful as dedicated circuits are idle during silent periods.

### Pros of Packet Switching over Circuit Switching

1. Better sharing of transmission capacity
2. Simpler, efficient and less expensive
3. Link use on demand

## Network of Networks

To build a network of networks, all ISPs need to be linked together.

Models of the internet:

1. Naive approach 

    Mesh network of all ISPs (Costly because of seperate communication links).

2. Global Transit ISP

    Interconnect all ISPs with 1 central global transit ISP (Costly).

3. Access ISPs with Global ISPs

    Lot of access ISPs with multiple global ISPs (desirable, but need to add regional ISPs and communication between global ISPs).

4. Internet Model with Points of Presence, multi-homing, peering, and Internet Exchange points added
   1. Points of Presence (POP) - Group of one or more routers in the providers network where customer ISPs can connect to provider ISPs
   2. Multi homing - Connect two or more provider ISPs
   3. Peering - Reduce cost of connectivity by pairing nearby ISPs by connecting their networks together so that traffic passes over a direct connection
   4. Internet Exchange Point - Place where multiple ISPs can peer together.

5. Access ISPs, regional ISPs, tier 1 ISPs, POPs, etc
6. Content Provider Networks
   1. Interconnect datacenters over a private network, which bypass the upper tiers of internet by peering with lower tier ISPs, either directly or through IXPs.

## Delay, Loss and Throughput in Packet-Switched Networks

The most important delays to consider in a packet switched network are
1. Nodal processing delay
2. Queuing delay
3. Transmission delay
4. Propogation delay


The time required to examine the packet headers and determine where to direct the packet is the part of processing delay. It can also include the time required to check bit errors.

Queueing delay is the wait to be transmitted onto the link from the queue. The length of this delay depends on the number of early arriving packets that are queued and waiting for transmission onto the link.

Transmission delay is L/R, the amount of time required to push all of the packets bits onto the link. 

Propogation delay is the time taken to reach the destination router from when the packet is pushed onto the link. This is given by d/s where d is the distance between the routers and s is the speed of the medium.

Nodal delay is given as the sum of all these delays.

Traffic intensity on a link is defined as La/R where a denotes the average rate of packet arrival. Average queuing delay follows an exponential distribution with traffic intensity, i.e, delay reaches infinite when traffic intensity > 1. The fraction of lost packets increases with increase in traffic intensity as well.

For N-1 routers, the total end-to-end delay is given by N * (processing delay + transmission delay + propogation delay).

A traceroute is a simple program that sends multiple packets to an undefined destination, in which each router sends a message of the name and address of the router the packet encounters on its path.

The instantaneous throughput at any instant of time is the rate at which a destination host is receiving a file.
The average throughput is given by F/T where F is the number of bits in a file and T is the time taken to transmit the file.

For a network, the throughput is the minimum of the transmission rate of each link, as the lowest transmission rate causes a bottleneck link.

## Protocol Layers and their Service Models

The service model of the internet is divided into layers which provided services by
1. Performing actions within the layer
2. Using the services of the layer underneath it

The seven layer OSI model of the Internet Protocol Stack is arranged as
1. Application
   1. The application layer is where the network applications and protocols such as HTTP, SMTP, etc reside. A packet in this layer is called a message.
2. Presentation
   1. The role of the presentation layer is to provide services that allow communicating applications to interpret the meaning of data exchanged (compression and encryption).
3. Session
   1. The session layer provides for delimiting and synchronizing data exchange, including checkpoints and recovery.
4. Transport
   1. The transport layer transports application layer messages between application endpoints. TCP and UDP is used here, and each packet in this layer is called a segment.
5. Network
   1. The network layer is responsible for moving network layer packets known as datagrams from one host to another, which delivers segments to different transport layers. Includes the IP protocol.
6. Data Link
   1. The data link layer allows the network layer to move packets from node to node. The packets here are called frames.
7. Physical
   1. The physical layer moves individual bits within the frame from one node to another.

The 5 layer model does not have the presentation and session layer.

Major drawbacks of the OSI Model: 
1. One layer may duplicate the functions of another
2. One layer may need information present only another layer

The protocol stack is a collection of all the protocols of all these layers.


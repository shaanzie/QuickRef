# The Network Layer

## Datagrams

A network layer packet is referred to as a datagram. The fields in a datagram are
1. 4 bit Version Number
2. 4 bit Header Length
3. 8 bit Type of Service 
4. 16 bit Datagram length
5. 16 bit Identifier
6. 5 bit Flags
7. 13 bit Fragmentation offset
8. 8 bit TTL
9. 8 bit Upper Layer Protocol
10. 16 bit Header Checksum
11. 32 bit Source IP Address
12. 32 bit Destination IP Address
13. 32 bit Options
14. Data

The header checksum is calculated by summing up 32 bit words and taking their 1s complement. That added with the entire packets words plus the checksum yields all 1s at the receiver's end if data integrity is preserved. Error checking is done both at the Network layer and the Transport Layer, as only the IP header is checked in the network layer, while TCP checks the entire payload.

## Fragmentation

The maximum amount of data a link layer frame can carry is called the Maximum Transmission Unit (MTU). It places a hard limit on the length of the IP datagram. The problem arises when each of the links along the route between the sender and destination have different MTUs. 

To overcome this, fragmentation is carried out on the data to make two or more smaller IP datagrams and encapsulate them into single link layer frames.

Fragments need to be reassembled before they reach the transport layer at the destination and this is done on the end systems.

The identification, flag and fragmentation offset determine whether a fragment is a standalone frame or part of a bigger payload. The last fragment has a flag = 0 and identification from the same sender is incremented for each fragment.

To determine whether a fragment is missing, the offset is used to specify where the fragment splits. Incomplete datagrams are hence discarded.

The drawbacks of fragmentation are:
1. Complicates logic at routers and end systems
2. Can be used to create DoS attacks, where overlapping fragments are sent to hinder reassembly.

## IPv4 Addressing

The boundary between a host and its link to the internet is called an interface.

IP addresses are 32 bit fields and are written in dotted decimal notation, where each byte is a decimal.

A network conecting three host interfaces and a router interface is called a subnet. 

IP addressing assigns an IP to each subnet, where /x denotes the subnet mask.

To determine subnets, detach each interface from its host or router, creating an island of isolated networks, with interfaces terminating at the end points of the isolated network. Each such network is a subnet.

Classless Inter-Domain Routing (CIDR) generalises subnet addressing. The x most significant bits of an address a.b.c.d/x are the prefix, and these are the only bits considered for addressing. The last 32 - x bits are used to identify different devices on the network.

Classful addressing involves subnets of 8 being of class A, 16 being of Class B and 24 being of class C. This led to poor utilisation of address spaces.

To get a block of IP addresses, the network administrator must first contact the ISP, which would provide addresses from a larger block of addresses already allocated to the ISP.

### Dynamic Host Configuration Protocol

Host addressing is usually done through the Dynamic Host Configuration Protocl. DHCP can give permanent or temporary IPs and can also allow a host to learn additional information like subnets, address of routers or the DNS.

DHCP is a plug-and-play protocol, and a client-server protocol.

DHCP addressing is done by,
1. Service Discovery : Find a DHCP server to interact with using a DHCP discover message, which the client sends to port 67 via UDP, encapsulated in an IP datagram, and then sends it to 255.255.255.255 and a source of 0.0.0.0 to all the nodes on the subnet
2. Server Offer : The DHCP server responds with a DHCP offer message that is broadcast on 255.255.255.255 and contains the transaction ID and proposed IP, network mask and an IP address lease time for validity.
3. Server Request : The new client chooses an offer from this pool of offers and responds with the DHCP request.
4. DHCP ACK : Server sends an acknowledgement to the client that it has accepted the request.

The main drawback of the DHCP is that a new IP is required for each node, i.e, there is no mobility.

### Network Address Translation

The Network Address Translation assigns a realm of private addresses per router, which is meaningful only within that network. The NAT router behaves as a single IP to the outside, who's IP is determined by DHCP and the router has its own DHCP for addressing devices connected to it.

The NAT table allows NAT enabled routers to forward packets internally.

Objections with NAT:
1. Port numbers are meant to be used for addressing processes, not hosts
2. Routers should process packets only upto layer 3
3. Violates end-to-end argument (hosts should talk to each other)
4. Use IPv6, not stopgap solutions like NAT
5. Interferes with P2P applications (peer can't act as a server)

The workaround for NAT to interface P2P networks is to use an immediate peer not behind a NAT to establish a TCP connection. This is called connection reversal and is mainly used for NAT traversals.

## Internet Control Message Protocol

Internet Control Message Protocol (ICMP) is used by hosts and routers to communicate network layer information to each other, usually for error reporting. ICMP has a type and a code field and contains the header and the first 8 bytes that caused the generation of the ICMP message.

The source quench message, for example, is used to allow a congested router to send an ICMP message to reduce a host's transmission rate. Ping, which is ICMP type 8 and code 0, is another example.

## IPv6

The IPv6 datagram made the following changes,
1. Expanded addressing capabilities
2. Streamlined 40 byte header
3. Flow labeling and priority

The IPv6 datagram fields are
1. 4 bit Version Number
2. 8 bit Traffic class (same as TOS)
3. 20 bit Flow label
4. 16 bit Payload length
5. 8 bit Next header : Protocol to deliver to
6. 8 bit Hop Limit : Incremented at each hop, discard datagram if exceeded
7. 128 bit source address
8. 128 bit destination address
9. Data

The fields that were removed from IPv4 are
1. Fragmentation : IPv6 does not fragment. If a datagram is too big, a packet-too-big ICMP message is sent and the packet is dropped.
2. Header Checksum : Redundant as TCP already checks this
3. Options 

Migration from IPv4 to IPv6 is in the process, with a dual stack approach where nodes are enabled with both IPv4 and IPv6 addresses. Tunneling can be done, where the entire IPv6 datagram can be tunneled through intermediate IPv4 devices.

The main reason to migrate to IPv6 was the larger addressing space. 

### Representation

The binary notation of IPv6 is converted to 8 hextets of hexadecimals, each 16 bits long. Leading 0s in IPv6 can be abbreviated. Zero compression is also done where one run of consecutive 0s is omitted.

A mixed notation is also allowed where an IPv4 address can be embedded in the IPv6 address. The rightmost two sections are converted to the dotted decimal format.

IPv6 allows heirarchical addressing, which means it allows /x on the CIDR notaton standards.

### Address Space

There are three types of IPv6 address
1. Unicast Addressing : Defines a single interface, where packets sent are routed to a single system.
2. Anycast Addressing : Defines a group of computers, represented by a single address. Packets are delivered to the first member of the network reached. Addresses are assigned from the unicast block.
3. Multicast Addressing : Defines a group of computers. All members of the group get the same copy of the packet and relevant systems work on the packet.

### Address Space Allocation

1. Global Unicast Address Block
   1. Used for unicast communication
   2. Prefix : 001
   3. CIDR : 2000::/3
   4. Size : 2 ^ 125 addresses
   5. Address : 
      1. 48 bit Global Routing Prefix
      2. 16 bit Subnet Identifier
      3. 64 bit Interface Identifier
   6. The link layer address can be embedded in the Interface ID, for 64 and 48 bit systems. 
      1. For EUI-64, change the 7th bit in the MAC address
      2. For EUI-48, change the 7th bit in the MAC address and add 15 ones and 1 zero (FFFE) to the middle of the identifier
2. Special Addresses
   1. Addresses not assigned to individual systems
   2. Prefix : 0000::/8
   3. The types of special addresses are
      1. Unspecified - 0000::/128
      2. Loopback - 0000::1/128
      3. Compatible - 0000::/96 followed by IPv4 address
      4. Mapped - 0000::FFFF/96 followed by IPv4 address
   4. These are designed in such a way that while calculating checksum, one can use embedded or total addresses because the extra 0s don't influence the checksum calculation.
3. Other assigned blocks
   1. IPv6 uses two large blocks for private addressing and one large block for multicast addressing.
   2. A subblock in a unique local unicast block can be privately created and used by a site. A packet carrying this block does not expect to be routed.
      1. Prefix - FC00::/7
      2. Identifier - 1111 1110
      3. The next bit can be 0 or 1 depending on whether the address is selected locally or by an authority
      4. The next 40 bits are a random number, making the probability of duplication really small.
      5. The next 16 bits are the subnet ID
      6. The next 64 bits are the interface ID
   3. A link local address is used like a private address on the network
      1. Prefix - FE80::/10
      2. 10 bit identifier as 1111 1110 10
      3. The next 38 + 16 bits are all 0s
      4. The next 64 bits are the interface ID
   4. Multicast addresses are used to define a group of hosts
      1. Prefix - F000::/8
      2. 8 bit identifier as 1111 1111
      3. The next 4 bits are a flag for permanent or transient
      4. The next 4 bits are the scope of the group addresses
      5. The next 112 bits are the group ID
   
### Autoconfiguration

Autoconfiguration is when an IPv6 address gets assigned to a system autonomously. This is done by,
1. The host first creates a link local address for itself by taking 1111 1110 and adding 54 zeroes, followed by a 64 bit MAC address as the interface ID.
2. The host then sends its neighbours a sociliation message and waits for a neighbour advertisement message. If any host in the subnet is using the same link local address, the autoconfiguration fails and an alternative protocol is used.
3. If uniqueness is confirmed, the host stores this as the link local address. It then sends the router a solicitation message and receives a router advertisement message with the global unicast prefix and subnet prefix to be attached.

### Renumbering

Renumbering is done to chnage the service provider for sites and organisations.
1. If the site changes provider, the address prefix needs to be changed.
2. The router connected to the site provides a new prefix and disables the old prefix after a while.

This causes a disadvantage as DNS faults occur, but this is circumvented by the advent of the next generation DNS.

### Advantages of IPv6 over IPv4

1. Better header fomrat : options seperated from base header, which speeds up routing
2. New options field
3. Allowance for extension : allows protocol extension
4. Support for resource allocation : Traffic class and flow label can allow special packet handling
5. Security 

### Concept of Flow and Priority in IPv6

To a router, a flow is sequence of packets that share the same characteristics. A router that supports flow handling has something called a flow table. The table has an entry for each active flow label, where each entry defines the services required by the corresponding flow label. When the router receives a packet, it consults the flow label table to find the corresponding entry for the flow label value in the packet, and then provides the services mentioned in the entry. In its simplest form, the flow label can be used to speed up the processing of the packet by a router, such as finding the next hop. This can be used, for example, in real time audio and video transfer.

### Fragmentation and Reassembly in IPv6

Fragmentation of IPv6 can happen only at the source, and not by the routers, and the reassembly can take place only at the destination. This is done to speed up routing at the routers. 

### Extension Header

The IPv6 datagram can support 6 extension headers
1. Hop-by-Hop : To pass information to all routers visited by a datagram.
   1. Pad1 : 1 byte long option designed for alignment purposes
   2. PadN : N byte long option for alignment
   3. Jumbo Payload : Longer payload length required.
2. Destination : When source has to give information only to the destination. Only the Pad1 and PadN options are defined for this.
3. Source Routing : Combines concepts of strict and loose source route options in IPv4
4. Fragmentation : Only source can fragment the data, using path MTU discovery technique to find the smallest MTU along a packet's path.
5. Authentication : Validates the message of the sender and ensures the integrity of the data.
6. Encrypted Security Payload : Provides confidentiality and guards against eavesdropping.

### Comparison of options between IPv4 and IPv6

1. The no operations and end of option fields in IPv4 are replaced by Pad1 and PadN.
2. The record route option is not implemented in IPv6 because it is not used.
3. The timestamp option is not implemented because it is not used.
4. The source route option is called the source route extension header in IPv6
5. The fragmentation fields have moved to the extension header.
6. New authentication header in IPv6
7. New encrypted security payload extension header in IPv6.
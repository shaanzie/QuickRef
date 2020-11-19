# Vulnerabilities on Blockchain

- The five most common blockchain attack vectors are
  - Blockchain network
  - User wallet
  - SCs
  - Transaction verification mechanisms
  - Mining pools

- Distributed Denial of Service
  - Hard to execute on blockchains
  - Consume all its processing resources with numerous requests

- Transaction malleability attacks
  - Trick the victim into paying twice
  - Alter transaction ID and broadcast transaction with a changed hash and have it confirmed before the original

- Timejacking
  - Exploits a theoretical vulnerability in timestamp handling
  - Hacker alters the network time counter of the node and forces node to accept an alternate blockchain
  - Add multiple fake peers with incorrect timestamps

- Routing attacks
  - Tamper with transactions before pushing them to peers
  - Divide network into partitions that cannot communicate with each others
  - Consists of two attacks
    - Partition attack
    - Delay attack, which tampers with propagating messages and sends them to the network

- Sybil attack
  - Assign several identifiers to the same node
  - Takes control of multiple nodes, and the victim is surrounded by fake nodes
  - Victim starts to double spend
  - Prevented by
    - Increasing cost of creating a new identity
    - Requiring some trust to join the network
    - Determine user power based on reputation

- Eclipse attacks
  - Control a large number of IP or to have a distributed botnet
  - Overwrite the addresses in the tried table of the victim node and waits until node is restarted
  - After restarting, all outgoing connections redirect to IPs controlled by hacker

- Long range attacks on proof of stake networks
  - Simple
    - Naive implementation of PoS, where nodes dont check block timestamps
  - Posterior corruption
    - An attempt to mine more blocks than the main chain in a given time frame
  - Stake bleeding
    - Copying a transaction from the honestly maintained blockchain to a private blockchain maintained by the attacker

- User wallet attacks
  - Use phishing, dictionary attacks etc to get wallet information

- Dictionary attack
  - Attempt to break a victim's cryptographic hash and salt by trying hashes of common passwords

- Vulnerable signatures and flawed key generations are also possible


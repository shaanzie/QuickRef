# Consensus Mechanisms

- Distributed Consensus
  - Procedure to reach a common agreement in a distributed and decentralised environment
  - Coordinated through message passing between nodes
  - Can be
    - Synchronous
    - Asynchronous

- Why consensus
  - Reliability
  - Fault Tolerance

- Objectives
  - Agreement
    - All loyal nodes decide on the same value
  - Termination
    - All nodes terminate consensus process
  - Validity
    - The value agreed upon should be proposed by a node at the beginning
  - Fault Tolerant
    - Malicious nodes do not leave the consensus faulty
  - Integrity
    - No node can make a decision more than once in a single cycle

- Miners
  - Multiple miners come to a consensus on who should add the block to the blockchain

- Why is consensus hard?
  - Nodes may crash
  - Nodes may be malicious
  - Network issues

- Fault tolerance consensus mechanisms
  - Crash fault tolerance
    - PAXOS
    - RAFT
  - Byzantine Fault tolerance
    - BFT
    - PBFT

- How do we choose which consensus mechanism to use?
  - Speed of writing blocks
  - Type of network
  - Number of miners, writers or validators
  - "Finality" of a block
  - Degree of trust on nodes

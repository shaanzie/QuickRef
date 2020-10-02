# Distributed Consensus

- Distributed Consensus
  - A procedure to reach a common agreement in a distributed or decentralized multi-agent platform
  - Message passing system
  - Why Consensus
    - Reliability
    - Fault tolerance

- Faults
  - Crash fault
    - Node suddenly crashes or becomes unavailable
  - Network faults
    - Network gets partitioned
  - Byzantine Faults
    - Node starts behaving maliciously

- Properties
  - Termination
    - Every correct individual decides some value
  - Validity
    - If all individuals propose the same value, then all correct individuals decide on that value
  - Integrity
    - Every correct individual decides on one value, proposed by an individual
  - Agreement
    - Every correct individual agrees on the same value

- Correctness
  - Safety
    - Correct individuals do not agree with an incorrect value
  - Lively
    - Every correct value must be accepted eventually

- Why do we need consensus
  - Node does not know all peers
  - Some nodes can perform malicious transactions

- Consensus in Bitcoin
  - Every node has a block of transactions that have been reached into the consensus
  - The nodes also have a list of outstanding transactions to be validated


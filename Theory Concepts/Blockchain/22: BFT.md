# BFT

- Byzantine Generals Problem
  - Paxos and Raft can tolerate N/2 - 1 number of crashes
  - For malicious nodes, we need a mechanism to accomodate for faulty nodes in the network that are functionally active

- Three Byzantine Generals Problem
  - Faulty Lieutenant
    - Follow commander's order
  - Faulty Commander
    - Majority voting

- Four Byzantine Generals Problem
  - Faulty Lieutenant
    - Commander sends a message to each of the lieutenants
    - Majority voting can be used
  - Faulty Commander
    - Majority voting

- Byzantine Generals Model
  - N number of processes with at most f faulty processes
  - Reliable, synchronous system
  - Receiver always knows the sender

- Lamport-Shostak-Pease Algorithm
  - Base condition
    - Broadcast(N, t = 0)
      - N processes
      - t is an algorithm parameter
    - Commander decides on its own value
  - If pulse message is not found, undefine
  - If it is found and the sender is from the commander, the node accepts the message
  - More than 2/3rd of the nodes must not be faulty for this to work

- Practical BFT
  - Ensure safety over async network
  - Low overhead
  - Slight increase in latency
  - Primary nodes - leader nodes
  - Secondary nodes - backup nodes
  - Ensures privacy
  - Lieutenants transmit response directly to client
  - Working
    - A state machine is replicated across different nodes
    - 3f + 1 replicas where f are the number of faulty replicas
    - Replicas move through a succession of configurations, known as views
    - One replica is primary, and the others are secondary
    - The view changes when the primary is detected as faulty
    - Only messages from current views are accepted
    - Client sends request to primary
    - Primary broadcasts to backups
    - The backups respond directly to the client node
    - Client waits for f + 1 replies with the same result, where f is the maximum number of faulty replicas that can be tolerated
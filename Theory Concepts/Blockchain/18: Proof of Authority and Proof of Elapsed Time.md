# Proof of Authority and Proof of Elapsed Time

- Proof of Authority
  - Best suited for private, permissioned blockchain
  - Collaborative consensus
  - Transactions validated by approved accounts
  - Validator nodes run consensus software
  - Developed to mitigate spam attacks

- Validators selected as authority
  - Only validators can add transactions and blocks
  - Suited for distributed trusted networks
  - Reputation and trust is used to select a validator
  
- Conditions that may vary from system to system
  - Valid and trustworthy identities
  - Difficulty to become a validator
  - Standard for validator approval

- Advantages of PoA
  - Energy efficient
  - Fast
- Disadvantages of PoA
  - Centralized
  - Validators visible to everyone

- Proof of Elapsed Time
  - Competitive consensus
  - Participants identify themselves before joining
  - Built to run in a secure area of the central processor called a trusted execution environment
  - Lottery based system that randomly selects a node from a pool of validating nodes
  - Probability of node being selected increases based on how much porcessing resource the node has contributed
  - Control cost of consensus process
  - Internal project, every node knows each other

- Verification
  - Special verification is required from a node to join the network
  - Used by Intel's Software Guard Extension
  - Creates an attestation for a piece of code and protects the code from external access

- Process
  - A node downloads the PoET code and generates an attestation(key)
  - The node forwards this key requesting to join
  - The new node has its own timer object which is a random value
  - All nodes are initialised with a random time

- Advantages of PoET
  - Low cost of upkeen
  - Scalable to operation

- Cons of PoET
  - Needs specialized hardware
  - Must know participants in the network
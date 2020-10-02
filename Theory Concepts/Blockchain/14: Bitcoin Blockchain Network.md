# Bitcoin Blockchain Network

- Bitcoin is a permissionless blockchain network
  - Decentralised digital currency
  - No central authority, uses peer-to-peer technology
  - Two broad operations
    - Transaction management
      - Transfer of coins
    - Money issuance
      - Regulate monetary base

- Creation of coins
  - Decreases geometrically for every 4 years
  - Miners get less rewards as time progresses
  - Mining fee is paid by increasing transaction fee

- Sending payments
  - Ensure 3rd party cannot spoof a user
  - Bitcoin uses public key cryptography to make and verify digital signatures
  - Each person has one or more addresses associated with a pair of public and private keys
  - Transfers
    - Sign transaction with her private key
    - Anyone can validate the transaction with the sender's public key
    - Receiver has to send his address to sender
    - Sender adds address and amount of bitcoins to transfer in a transaction message
    - Sender signs the transaction with her private key, and announces her public key for signature verification
    - Anyone in the network validates the transaction
  - Double spending
    - Same bitcoin amount used for more than one transaction
    - To prevent this
      - Details about the transaction are sent and forwarded to as many other nodes
      - We use a blockchain here, containing a record of all transactions
      - Maintained by all peers, and anyone can identify double spending
      - To be accepted in the chain, transaction blocks must include a proof of work, generated in the mining procedure
      - If one block is modified, all following blocks will have to be recomputed
      - When multiple valid continuations appear, the longest chain is accepted and extended, and the rest of the blocks are orphaned
      - Once a transaction is committed in the blockchain, all in the network can validate all transactions using sender's address
      - This prevents double spending

- Bitcoin anonymity
  - Each user has an anonymous identity on the blockchain network
  - Wallet generates public and private keys
  - The bitcoin address is used for the transaction
    - Corresponds to a public key based on ECDSA digital signature algorithm
    - Each person can have more than one address, each with its own balance
    - Difficult to know which person owns what amount

- Bitcoin P2P network
  - Runs on TCP port 8333, adhoc
  - Random topology
  - All nodes are treated equally
  - New nodes can join anytime, non responding nodes are removed after 3 hours

- Joining a P2P Bitcoin network
  - The node to connect to is called a seed node
  - Seed node gives the new node an address, and adds it to the address list
  - The address list allows all other nodes to connect to it
  - Then, it retrieves the most recent blockchain copy
  - Now, it can start transactions
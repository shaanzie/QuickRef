# Proof of Work

- It defines solving a computational challenging puzzle in order to create new blocks
- It defines a solution that is difficult to find but is easy to verify
- A nonce is a number that's generated once and used only once
  - Difficult to find

- Each node (miners) needs to solve math puzzle to propose transaction
  - Lot of computation
  - Node that finishes first adds block to blockchain

- Steps
  - Network server sends puzzle
  - Puzzle solved by the miners and sends solution to the server
  - Server checks solution and sends reward accordingly

- New block is added using the hash of the previous blocks and the nonce
  - Should be lesser than the difficulty level

- Bitcoin uses HashCash proof of work
  - Given data A, find X such that hash of X appended to A results in a number lesser than B
  - Adds X-HashCash header to request

- Protects from corruption as long as 51% or more of the blocks are legitimate
  - Tested
  - Slower and safer, and cannot rollback transactions
  - Trustless

- Disadvantages
  - 51% risk
  - Slow
  - Costly
  - Susceptible to centralization

- Majority Attack
  - When a group of users control the mining power
  - If all nodes are malicious, they can get unlimited rewards and reverse transactions
  - May cause blocks to be lost if they don't belong to the majority miner pool
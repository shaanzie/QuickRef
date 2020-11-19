# Smart Contract

- A smart contract is similar to a contract in the physical world, but is digitally stored and automatically verifies the transaction and fulfills it

- Smart contracts are
  - Immutable
  - Distributed

- Working of a smart contract
  - Independent storage is created where A and B can put values but cannot remove any
  - B puts money for rent in storage
  - A puts the address and the code to her apartment in storage
  - A gets payment confirmation and B receives the address and code
  - If B goes to location and code is right, A gets the payment
  - If code is wrong, B gets his money back
  - If B doesnt come to location, A gets liquidated damages payment and B gets the rest
  - At the end, contract is fulfilled

- Goals of a smart contract
  - Removal of manual intervention and oversight
  - Reduction in cost and time
  - Automated transfer of funds
  - Flexibility in contract

- There are two types of SCs
  - Deterministic
    - SCs that dont depend on outside information out of the blockchain
  - Non-deterministic
    - Outside paty needed (Oracle) to facilitate smart contract execution

- Creation and Deployment of a SC
  - Understand use case
  - Create basic architecture for interaction
  - Start development
  - Test the SC
  - Record all transactions while testing
  - Implement security with stuff such as bug bounty

- Advantages of SCs
  - Direct dealing with customers
  - Resistant to failure
  - Immutability
  - Fraud reduction
  - Cost efficiency
  - Records keeping

- Components of an ethereum blockchain
  - Node/Client: A node is device that communicated with the ethereum network
  - Block: A block is a package of data that has zero or more transactions, the hash of the previous block, and some other optional data
  - Miners: Miners add blocks to the blockchain
  - Proof of work: An activity that miners undertake to write new transactions to a block
  - Ethereum virtual machine: Decentralized computing platform
  - Ether: Name of the currency in ethereum
  - Gas: Pricing value required to successfully perform and execute a transaction
  - Gas limit: Maximum amount of gas you are willing to pay for a smart contract execution
  - Mining Pool: Groups of miners that work together to mine blocks on the network
  - Main-net: Main ethereum blockchain network
  - Whisper client: Lets nodes in the network communicate with each other
  - Swarm client: Decentralized storage platform by ethereum

- Use cases for Smart Contract Execution
  - Automated triggers
    - Execute a contract under a certain condition
    - Rebalance pool periodically
    - Poking oracles to refresh data
    - Paying out pro-rated dividends for security tokens
  - State and Event Monitoring
    - Monitoring allows to know when conditions are met
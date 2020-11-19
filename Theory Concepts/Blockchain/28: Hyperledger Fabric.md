# Hyperledger Fabric

- Hyperledger is an open source community focusing on developing a suite of stable frameworks, tools and libraries for enterprise-grade blockchain deployments

- For enterprise blockchain, the following requirements exist
  - Participants need to be identified
  - Permissioned networks
  - High transaction throughput
  - Low latency
  - Privacy

- Hyperledger fabric is an open source enterprise-grade permissioned distributed ledger technology platform
  - Highly modular and configurable
  - Supports smart contracts in general purpose programming languages
  - Prmissioned
  - Pluggable consensus protocols to fit particular use cases

- Features of HF
  - Assets
    - HF provides ability to modify assets using chaincode transactions
    - Represented as KV pairs, in JSON or binary
  - Chaincode
    - Software that defines assets, and the transaction instructions to modify it
    - Enforces rules for reading and altering KV pars
    - Executes against the ledger's current state and initiated through a transaction proposal

- Ledger features
  - Sequenced, tamper-resistant record of all state transitions
  - Comprises of a blockchain to store the immutable, sequenced record of blocks
  - Query and update the ledger using key-based lookups, range queries and composite key queries
  - Read-only queries using a rich query language
  - Transactions consist of versions of KVs read and written in chaincode
  - Transaction contains signatures of every endorsing peer
  - Transactions ordered into blocks and delivered by an ordering service
  - Peers validate transactions against endorsement policies
  - Versioning check before appending block to ensure assets were not changed
  - Immutable once transaction is committed
  - Configuration block defines policies, access control lists, etc
  - Channels contain Membership Service Provider instances allowing for crypto materials to be derived from different certificate authorities

- The immutable ledger is on a per-channel basis, as well as the chaincode

- Chaincode can be intalled only on peers that need to access the asset states to perform operations

- Private data collections are used to segregate data into a private database, logically seperate from the channel ledger

- PKI is used to generate cryptographic certificates tied to organizations, netwrork components and end user or client operations

- Consensus in HF is defined as the full circle verification of the correctness of a set of transactions comprising a block
  - First checks endorsement policies
  - Then versioning
  - Finally protection under double spend and data integrity checks
  - Also does ongoing identity variations

- HF follows a execute-order-validate architecture
  - Transactions need not be executed by each peer
  - A subset of peers can endorse a given a transaction and satisfy its policy
  - The client must collect all the endorsements to say that its valid
  - Then, submit these to the ordering service, and then the service validates them
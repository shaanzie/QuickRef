# Blockchain on CIA Security Triad

- Confidentiality, Integrity and Availability (CIA) security triad model is one of the most popular security frameworks in Blockchain

- Confidentiality is a way to keep information hidden from unauthorized people

- Integrity is a way to protect the unauthorized tampering of information
  - Use hashing
  - Always one way, almost impossible to get data back from the hash result
  - Ledger stored as connected blocks, very hard to tamper

- Availability refers to ontime and reliable access to data
  - No single point of failure

- Hyperledger fabric offers features to achieve confidentiality with
  - Attribute based access control (ABAC)
  - Attribute Certificate Authority (ACA)
  - Hyperledger Fabric encryption literary

- Hyperledger fabric offers features to achieve integrity with
  - Committing a peer always validates the new block before adding it
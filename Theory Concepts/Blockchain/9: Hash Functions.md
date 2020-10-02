# Hash Functions

- A cryptographic hash function takes data and essentially translates it into a string of letters and numbers
  - Strings of uniform length for arbitrary length input

- Method
  - Private key generates a public key
  - One way hash functions convery public key to a unique address

- Popular hash functions
  - Message Digest (MD)
  - Secure Hash Function (SHA)
  - RIPEMD (RACE Integrity Primitives Evaluation Message Digest)
  - Whirlpool

- Examples
  - MD5
    - 128 bit hash
    - Collision resistance was broken after 2<sup>21</sup> hashes
  - SHA1
    - 160 bit hash
    - Collision resistance was broken after 2<sup>61</sup> hashes
  - SHA256
    - 256 bit hash
  - Keccak-256
    - 256 bit hash

- SHA256
  - Used in Bitcoin
  - Small changes in input reflect drastically in the final hashcode

- Properties
  - Deterministic
  - Pre-image Resistance
    - Should be hard to recover the input message
  - Collision resistant
  - Small changes in input changes the hash
  - Puzzle friendly
  - Quick computation

- Each block stores the hash of the previous block's header
  - Genesis has a random value

- Data structures
  - Pointers
  - Linked List

- Block Header
  - Version: Block version number
  - Time: Current Timestamp
  - Current difficulty target
  - Hash of the previous block
  - Nonce
  - Hash of the Merkle Root
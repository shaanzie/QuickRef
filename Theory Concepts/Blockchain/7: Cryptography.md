# Cryptography

- Cryptography is a method of secure communication between 2 interacting objects.

- Key components
  - Plaintext
    - Raw, unencoded, readable data
  - Encryption
    - Algorithm to convert plaintext to ciphertext
  - Ciphertext
    - Converted form of plain text
  - Decryption
    - Algorithm to convert ciphertext to plaintext
  - Ciphers
    - Algorithms for the encryption and decryption

- Objectives of cryptography
  - Confidentiality
  - Integrity
  - Non-repudiation
  - Authentication

- Keys
  - Public key
  - Private key

- Asymmetric cryptography
  - Public and Private key used together for encryption and decryption
- Symmetric cryptography
  - Only one type of key is used

- Types Cryptographic ciphers
  - Single Key / Symmetric Key
    - AES, DES
    - Same key not used for decryption and encryption
  - Public Key / Assymetric Key
    - RSA
    - Same key used for both ops

- Symmetric Key Cryptography
  - Same key is used at sender and receiver
  - AES, DES
  - Types of ciphers
    - Transposition
    - Substitution
    - Stream
    - Block

- Transposition Cipher
  - N digit key
  - Convert input to matrix format with N columns and fill the plaintext in the rows
  - Reorder columns according to column headers defined by N digit key
  - Generate the cipher text from the matrix row by row

- Substitution Cipher
  - A key word is taken, say 4
  - All input characters are shifted by 4 characters

- Stream Cipher
  - Plain byte stream M
  - Pseudo random byte generator encrypts with a key (keystream generator)

- Block Cipher
  - Whole block gets encrypted with a cipher

- Asymmetric Key Cryptography
  - Seperate key for encryption and decryption
  - RSA, Diffie Helman

- RSA
  - Choose 2 large prime numbers
  - Compute n = pq & z=(p-1)(q-1)
  - Choose number e is less than n which has no common factor (more than 1) with z
  - Find d such that (ed - 1) is exactly divisible by z
  - Keys are generated using n, d and e (Public key is (n, e) and private key is (n, d))
  - Encryption: c = m<sup>e</sup> mod n where m is the plain text and c is the ciphertext
  - Decryption: m = c<sup>d</sup> mod n
  - Public key is shared and private key is hidden
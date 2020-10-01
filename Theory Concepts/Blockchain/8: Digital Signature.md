# Digital Signature

- Digital signatures are like electronic fingerprints.
- Digital signatures use public key infrastructure (PKI).
  - Two seperate keys in encryption and decryption

- Why digital signatures?
  - Authenticity
  - Integrity
  - Non-repudiation

- Key components
  - Hash function
  - Public key cryptography
  - Public key infrastructure
  - Certificate authority
  - Digital certificates
  - Pretty Good Privacy (PGP) / OpenPGP

- Process
  - Signer provides the data
  - Hash algorithm generates hashcode
  - Encryption provides the digitally signed document
  - Document is received and hash algorithm and decryption generate hashcode and decrypted file
  - Document is verified

- Reducing signature size
  - Sign the message with receivers private key
  - Verify the signature using sendsers public key
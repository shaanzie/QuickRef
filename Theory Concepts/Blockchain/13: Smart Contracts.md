# Smart Contracts

- Smart Contract
  - Self executing contract with the terms of agreement between buyer and seller being directly written into lines of code
  - Transactions are transparent, trackable and irreversible
  - Gives
    - Autonomy
    - Trust
    - Backup
    - Safety
    - Speed
    - Savings
    - Accuracy

- Smart Contract Anatomy
  - Agreement Identification
    - Identifying cooperative opportunities for multiple parties
    - POtential agreements on transfer of rights and asset swaps
  - Condition Setting
    - Event/Temporal conditional triggers
  - Business Logic Coding
  - Digital Signature
  - Process education
  - Updating network

- Components 
  - Smart Contract Code
  - Smart legal contracts
    - Specification for the code as a substitute for legal contracts

- Solidity
  - A smart contract in Solidity includes
    - Data
      - Maintains current state of the contract
    - Function
      - Applies the logic for transitioning the state of the contract
  - Pragma directives enable some compiler features
  - OO HDL language
  - Helps create contracts for a lot of use cases

- Developing a smart contract
  - There are 2 types of variables
    - Value types
      - Types passed by values
    - Reference types
      - Complex types passed by reference

- Contract Structure
  - Contract Declaration
    - Declared through `contract`, and creates an empty contract
    ```
    contract PurchaseOrder {

    }
    ```
  - Adding data variables
    - INT, U (unsigned), 25 (256 bits)
  - Defining a constructor
    - Public constructor declared for deployment
  - Adding functions
    - Control capabilities
    ```
    function <function name> <access modified> <state mutator> <return value> {}
    ```
    - Get functions
      - Read stored values
    - Setter functions
      - Write/Update values
  - Deploying the smart contract
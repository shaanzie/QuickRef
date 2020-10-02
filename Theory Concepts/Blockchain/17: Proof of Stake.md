# Proof of Stake

- Competitive consensus algorithm
  - Alternative to PoW
  - Peercoin uses PoS

- Stake
  - Must lock a certain amount its currencies into an escrow account to participate in the block creation process
  - Person can mine or validate transactions based on how much cryptocurrency he holds
  - Coin age = coin * holding_days
  - High coin age has a higher probability of minting the next block
  - Blocks are forged, rather than mined
  - Uses transaction fee as reward
  - Shift to PoS after PoW

- Nothing at stake
  - Forking - two or more competing blocks
    - Validators build on all forks
    - Causes divergence, ambiguity
  - Stake cryptocurrency on both blocks
  - Little cost and economic incentive

- Factors to select forger
  - Stake age
  - Randomization
  - Node wealth

- To not favour the richest block always
  - Randomization selection
    - Lowest hash value and highest stake
  - Coin age selection
    - Based on how long tokens have been staked for
    - Once selected, coin age is set to 0

- Security
  - Stake acts as a motivator
  - Forger loses stake if malicious activity is detected
  - 51% attacks are mitigated this way

- Variants
  - Chained PoS
    - Chain PoS and PoW
    - First blocks with PoW and the others with PoS
    - Miners selected individually
  - BFT
    - Set of validators selected
    - Consensus reached based on majority
    - Multiple rounds of consensus
    - Tolerates 1/3rd of nodes being byzantine nodes
  - Delegated PoS
    - Reputation scores, better website and social media are used to select validators
    - Stakeholders elect witnesses to validate transactions
    - Paid fees for producing blocks
    - Only delegates can propose new blocks

- Advantages
  - Energy efficient
  - More expensive to attack than PoW
  - Scales easilt to handle transaction load and size

- Disadvantages
  - Rewards weighted to those who stake currency the longest
  - Wealthy get more control
  - May cause centralisation
# Proof of Capacity and Proof of Burn

- Proof of Capacity
  - Allows miners to mine for tokens with available space they have on their hard drive
  - In cloud, this is called for Proof of Space
  - Peers contribute free disk space for proportionate service
  - Peers get paid if their free space can be used by other peers that need more space

- Collaborative consensus
  - Farmers
    - Nodes that are securing transaction
    - Allocate non-trivial amount of memory or disk space
    - Use left over memory
    - Farmers don't fight to secure blocks
    - Scalable

- PoC miners use a 2 step system
  - Plotting
    - Create a random solution, called a plot, through the Shabal cryptographic algorithm and storing it on a miner's hard drive
    - Generates plot files with precomputed hashes. This contains groups of 256 KB, called nonces. These are divided into scopes of 8 KB.
    - Index value is used to index these files
  - Mining
    - Consists of miners reaching the solution, and whoever reaches it first, gets to mine the next block
    - A 32 byte hash called a Generation signature from the previous block, and the index, and the base target (based on last 24 blocks, difficulty level) together are used for the calculation

- Advantages of PoC
  - Environment friendly
  - Uses wasted hardware space
  - Used for malicious attack detection as well
- Disadvantages of PoC
  - New and not tested
  - Incentivisation an issue

- Proof of Burn
  - Non competitive
  - Validated by elected nodes
  - User pays fee by burning some currency
  - Sending currency to an address where it can never be retrieved
  - To secure things like land titles, records, data feeds, etc

- Advantages of PoB
  - Cheap
  - Scalable
  - Long term commitment
  - Not easy to tamper

- Disadvantages of PoB
  - Centralization
  - Limited functionality
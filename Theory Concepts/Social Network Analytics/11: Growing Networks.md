# Growing Networks

- Networks expand through the addition of new nodes
  - Not static entities
  - Random networks assume fixed nodes

- Nodes prefer to link to the more connected nodes, called preferential attachment
  - New nodes tend to connect to nodes with large degree
  - More connected a node is, the more likely it is to receive new links
  - Nodes with higher degree have stronger ability to grab links added to the network
  - Rich-get-richer rule, probability that a page experiences an increase in popularity is directly proportional to the page's current popularity

- Barabasi-Albert Model
  - Few hubs have a lot of connections, others have a few
  - The BA model generates networks based on preferential attachment
  - Considers two main ingredients
    - Growth
    - Preferential attachment
  - Generates scale-free networks
  - Algorithm
    - Start with m0 nodes, the links between which are chosen arbitrarily, as long as each node has atleast one link
    - Growth
      - At each timestep, add a new node with m < m0 links that connect the new node to m0 nodes already in the network
    - Preferential attachment
      - The probability P(k<sub>i</sub>) that a link of the new node connects to an existing node i depends on k<sub>i</sub> as P(k<sub>i</sub>) = k<sub>i</sub> / Sum(k<sub>j</sub>)
  - Properties
    - Degree distribution is scale free, and is a power law distribution
    - Average path length increases logarithmically with the size as l ~ ln N / ln ln N
      - Systematically shorter average path length than a random graph
    - New nodes or deleted nodes don't break the network
      - Only if the highest degree nodes are deleted, the network breaks
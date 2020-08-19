# Properties of Networks

- Path
  - In a network, a path is a sequence of nodes in which each node is connected by an edge to the next
  - It is a walk where there are no repeated nodes

- Path length
  - The distance between the two nodes, measured as the number of edges between them

- A path is interesting for several reasons'
  - Path means connectivity
  - Path captures indirect interactions in a network
  - Path is closelt related to small-world phenomenon
    - A person is a couple of edges away from everyone in the world
  - Path is related to many centrality measures

- The average path length is the average distance between any two nodes in the network
  - It is one of the three most robust measures of network topology

- Applications of path length
  - Small average path length facilitates the  quick transfer of information and costs
  - Power grid networks have fewer losses
  - Concept of small world strengthened

- Network diameter
  - Let L(i, j) denote the length of the shortest path (or geodesic) between i and j
  - The diameter is the largest distance between any two nodes in the network (largest geodesic).
  - The diameter defines the linear size of a network
  - Diameter is a signal about the ability of information or disease to diffuse on the network

- Linking behavior
  - Determines how links(edges) are formed in a social graph/network.
  - Two measures are discussed
    - Reciprocity
    - Transitivity

- Dyadic Relationships
  - A and B are not connected
  - A sends to B
  - B sends to A
  - A and B send to each other

- Reciprocity is a measure of the likelihood of vertices in a directed network to be mutually linked
  - What proportion of pairs have a reciprocated tie between them?

- Reciprocity is the extent to which two actors reciprocate each other's friendship or other interaction
  - It refers to responding to a positive action with another positive action

- Reciprocity considers closed loops of length 2, which can only happen in directed graphs.
- Reciprocity computation counts the number of reciprocal pairs in the graph. A directed graph can have a maximum of |E|/2 pairs.

- Reciprocity = (1/|E|) * Tr(A<sup>2</sup>)
- Maximum R is achieved when Tr(A<sup>2</sup>) = |E|, when all directed edges are reciprocated.

- Triadic relationships (between 3 nodes)
  - No ties
  - One tie
  - Two ties (open triad)
  - All three ties (transitive triad/balanced triad/closed triad)

- The counts of the relative prevelance of these 4 types across all possible triples give a sense of the extent to which a population is characterized by isolation, couples only, structural holes or clusters.
- There are 16 possible types of relations among 3 actors in a directed graph.
# Centrality Measures

- Accounts for the importance of nodes in a network

- Centrality Measures   
  - Degree: How many people can reach directly
  - Betweenness: How likely is this person to be the most direct route between two people in the network
  - Closeness: How fast can this person reach everyone in the network
  - Eigenvector: How well is this person connected to other well connected people

- Degree Centrality
  - Degree: Number of connections a node has to other nodes
  - Important nodes have many connections
  - Directed networks have
    - Indegree (Prestige)
    - Outdegree (Gregariousness)
    - Sum of both
  - Used to find popularity of a node
  - In egocentric networks, it is the sum of all actors directly connected to the ego
  - We cannot compare centrality across networks
    - For this, we normalise
    - We normalise with the maximum possible degree
    - Similarly, the concept is applied to directed graphs

- Closeness Centrality
  - Based on the notion of distance
  - If an actor is close to all others in the network, a distance of no more than one, then he or she is not dependent on any other to reach everyone
  - Measures efficiency or independence
  - With disconnected networks, closeness centrality must be calculated for each component
  - Measures the proximity of an entity to other entities in the social network
  - Way of detecting nodes that can disperse info efficiently
  - Nodes with the highest closeness score have the shortest distance to all other nodes
  - Closeness = reciprocal of the sum of the length of the shortest paths between the node and all other nodes in the graph
    - This can be normalised by N-1
  - We use this when
    - Research organizational netowrks
    - Importance of words in a document
    - Estimated time of arrival of information flowing through a network

- Betweenness Centrality
  - Quantifies the number of times a node acts as a bridge along the shortest path between two other nodes
  - Node is important if it lies in many shortest paths
  - Finds communication bottlenecks or community bridges
  - It is given by the number of shortest paths the node is involved in divided by the total number of shortest paths between two nodes
  - Normalisation is done by dividing the centrality by the pairs of vertices in the graph excluding the vertex
    - C/(N-1)(N-2)/2 in undirected, C/(N-1)(N-2) in directed
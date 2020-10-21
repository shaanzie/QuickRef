# Small World Networks

- Many real-world networks share two fundamental properties
  - Small world phenomenon: Distances in real-world networks are quite small
  - Scale free phenomenon: Degrees in real-world networks show an enormous amount of variability

- Small world phenomenon
  - A person is only a couple of connections away from any other person in the world
  - We are all linked by short chains of acquaintances

- Small world network
  - Most nodes are not neighbours of one another, but most nodes can be reached from every other by a small number of steps
  - Six degrees of separation
    - All people are six or fewer social connections away from each other
    - Distance between any two nodes in a network is unexpectedly small
  - There are short paths between most pairs of nodes, usually created by hubs
  - Combines two important ideas
    - Homophily
    - Weak ties
  - Typically, there is an over-abundance of hubs - nodes with a high number of connections
    - Serve as common connections mediating short paths between other edges
  - Homophily creates high clustering while weak ties produce a branching structure that reaches many nodes in a few steps
  - Networks with short-average path lengths and high clustering coefficients are considered small world networks
  - Defined to be a network where the typical distance L between two randomly chosen nodes grows proportionally to the logarithm of the number of nodes, i.e. L proportionates to log N

- Watts and Strogatz Model
  - Graphs can be classified according to two independent structural features, namely
    - The clustering coefficient
    - Average node-to-node distance
  - Purely random graphs built accordin to ER model exhibit
    - Small average shortest path length
    - A small clustering coefficient
  - Watts and Strogatz measured that in fact, many real-world networks have
    - Small average shortest path length
    - A clustering coefficient higher than expected by random chance
  - Their novel model has
    - Small average shortest path length
    - A large clustering coefficient

- The ER random graphs don't have two important properties observed in real world networks
  - ER graphs do not generate local clustering and triadic closure
    - Constant, random and independent probability of two nodes being connected, low clustering
  - ER graphs do not account for formation of hubs
    - Degree distribution of ER graphs converges to a Poisson distribution, rather than power law

- The WS model accounts for clustering while retaining short average path lengths
  - Interpolates between a randomized structure close to ER graphs and a regular ring lattice
- The WS model is able to atleast partially explain the small world phenomenon

- The WS model
  - Exhibits
    - Small average shortest path lengths
    - Relevant clustering as regular lattices
  - Is built by
    - Rewiring at random a small percentage of the regular edges
      - This is enough to dramatically reduce average path length without destroying clustering
  - Algorithm
    - Start with a ring of n nodes, where each node is connected to its k nearest neighbours, k/2 on each side
    - Fix a parameter p between (0,1)
    - Consider each edge (u,v) and rewire with probability p
      - Rewiring is done by replacing (u,v) with (u,w) where w is chosen uniformly at random from all possible nodes while avoiding self loops and link duplication
  - Regular lattice (p=0): no edge is rewired
  - Small world network (0 < p < 1): Some edges are rewired. Has local structure with some randomness
  - Random network (p=1): All edges are rewired
  - Generating small world graphs
    - Select a fraction p of edges and reposition one of their endpoints
    - Add a fraction of additional edges leaving underlying lattice intact
  - Average clustering coefficient and shortest path of a small world network depends on k and p
    - As p increases, shortest path decreases rapidly and the clustering coefficient decreases slowly

- Small World Experiment
  - Conducted by Stanley Milgram
  - Examines average path length for social networks of people in the USA
  - Human society is a small world type network characterised by short path lengths
  - Experiment
    - Picked randomly 296 random individuals in Nebraska
    - Everyone given a letter to be delivered to a stockbroker in Boston
    - Instructions
      - If you know the person, give it  to him, otherwise to someone closer to the target
      - Some information was provided, and chain of communication would continue until the target was reached
    - 64/296 reached, and average steps were between 5 and 6
  - Key points
    - Relatively large percentage reached the target
    - Paths were relatively short
    - People were able to find these short paths

- Six Degrees of Kevin Bacon
  - Oracle of Bacon
  - Connect any actor to Kevin Bacon in the smallest number of links possible
  - Two people are linked if they've been in a movie together
  - Bacon number is the number of links taken to reach Kevin Bacon, and rarely exceeds 4
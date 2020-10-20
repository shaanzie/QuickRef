# Random Networks

- Network science aims to build models that reproduce the properties of real networks
  - Need to decide where to place the links betweeen nodes to reproduce complexity
  - We place the links randomly between the nodes to model this

- Random friendships create characteristics observed in real networks
  - Early on, nodes form isolated groups
  - Later, mingling and group changes convert these isolated groups into networks

- There are two definitions of random networks
  - G(N, L) model
    - N labelled nodes are connected with L randomly placed links
    - Graph chosen uniformly at random from the collection of all graphs with N nodes and L edges
    - Fixes total number of links as L and the average degree is simply k = 2L/N
  - G(N, p) model
    - Each pair of N labelled nodes is connected by probability p
    - Network characteristics are easier to calculate
    - Models better real world networks as links cannot be fixed in real life

- Random Network Construction
  - G(N, p) model
  - Steps
    - Start with N isolated nodes
    - Select a pair and generate a number between 0 and 1
    - If the number is lesser p, then connect the two nodes
    - Repeat for all pairs
  - This is called the Erdos-Reyni network

- Properties of Random Networks
  - We can tune the behavior by varying p
  - When p is small
    - No giant component
    - Small isolated connected components
    - Diameter is small as all nodes are isolated connected components
  - As p gets larger
    - Graph gets densr
    - Giant component starts to appear
    - Isolated components become connected
    - Diameter value increases
  - As p continues to get larger, diameter starts shrinking due to new paths being generated
    - This is called phase transition
    - The giant component starts to grow
    - Occurs when z = 1 or p = 1 / (n - 1)
  - G(N, p) is the ensemble of graphs in which each graph appears with probability appropriate to its number of edges
  - Represented usually by average degree z
  - Average number of edges as a whole is (1/2)n(n-1)p
  - Average number of ends of edges is twice this, as each edge has 2 ends
  - Average degree of a vertex = (n-1)p ~ np
  - Many ensemble average properties can be calculated exactly in the limit of large n
  - The ER model shows a phase transition with increasing z at which a giant component forms
  - If  
    - np < 1 : No connected components of size larger than O(log(n))
    - np = 1 : Almost surely has a largest component who's size is of the order n<sup>2/3</sup>
    - np -> c > 1, where c is constant : Almost surely has a unique giant component containing a positive fraction of the vertices
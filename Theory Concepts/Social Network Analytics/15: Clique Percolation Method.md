# Clique Percolation Method

- A clique is a subset of nodes where each pair of nodes is connected through an edge, that is a complete sub-graph
  - A k-clique denotes the size of a clique of k nodes

- Clique Percolation Method (CPM)
  - Finds overlapping communities
  - Based on the concept of
    - Internal edges of communities are likely to form cliques
    - Intercommunity edges are unlikely to form cliques
  - Two cliques are adjacent when they share k-1 nodes
  - A union of all k-cliques that can be reached from each other through a series of adjacent k cliques is called a k clique community
  - Algorithm, given graph G and k (Find communities of size k or more)
    - Locate maximal cliques
      - Largest possible clique size can be determined from degrees of vertices
      - Starting from this size, find all cliques, and then reduce by size 1 and repeat
    - Convert from cliques to k-clique communities
      - Create a square matrix of size nxn where n is the number of cliques found
        - Each cell C[i, j] contains number of nodes shared by cliques i and j
      - If C(i, j) is less than k, delete
      - If C(i, j) is less than k-1, delete
      - Change all non-zeroes to 1
      - Combine adjacent cliques to form a community
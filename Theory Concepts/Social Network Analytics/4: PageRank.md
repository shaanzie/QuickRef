# PageRank

- Variant of eigenvector centrality
- A node's pagerank depends on the pagerank of other nodes

- Pagerank computation
  - In a network with n nodes, set all ranks as 1 or 1/n
  - Choose steps k
  - Perform sequence of k updates using the update rule
    - Each page divides its current pagerank equally across its out-going links and passes these equal shared to the pages it points to
    - Each page updates its new pagerank to be the sum of the shares it receives

- Pagerank is never created nor destroyed, hence no normalisation is required
- Document is considered more important if more important documents point to it
- PR(A) = (1-d) + d(PR(T1)/C(T1) + ... + PR(Tn)/C(Tn))
  - Where PR(A) is the pagerank of A
  - C(Ti) is the number of outgoing links on page Ti
- Pagerank is determined for each page independently
- Pagerank of Page T is weighted by the outbound links C(Ti)
  - The more outgoing links, the less A would benefit from a link on page Ti
- A damping factor d is used which can be set between 0 and 1, reducing the benefit of linking to a page

- 
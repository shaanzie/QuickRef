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

- The effect of inbound links
  - Each inbound link always increases that page's pagerank
  - Each additional link from page X increases the rank by d * (PR(X)/C(X))
  - Every page pointed to by A also benefit
  - If pages pointed to by A points back to A, the benefit is increased further

- The effect of damping factor
  - Degree of propogation from one page to another from a link is determined by the damping factor d
  - Higher the damping factor
    - Larger the effect of an additional inbound link for the pagerank of a page that receives the link
    - The more evenly distributed the pagerank is over other pages of a site

- The effect of outbound link
  - The total pagerank remains the same
  - The pagerank benefit of one site equals the pagerank loss of the other

- The effect of number of pages
  - Adding a new page may decrease a page's pagerank substantially
  - It also might marginally increase a page's pagerank

- Constraints on pagerank
  - If there are no links from within a group of pages to the outside, then the group is said to be a spider trap
  - Rank sink can occur when a network of pages form an infinite cycle
  - Dead-ends occur when pages have no outlinks
  - If a page contains a link to another page which has no outlink, the link is known as a dangling link

- Purpose of pagerank in social networks
  - Solve link predictions to find individuals that will become friends soon
  - Estimates social status and power
  - Evaluates potential influence of a node on the opinions of a network
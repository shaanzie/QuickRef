# Pairwise Stability

- Nash equilibrium has a drawback that players cannot discuss their decisions   
  - To model this, stability concept takes this fact into account

- Pairwise stability
  - A network is pairwise stable if
    - for all ij in g, u<sub>i</sub>(g) >= u<sub>i</sub>(g-ij) and u<sub>j</sub>(g) >= u<sub>j</sub>(g-ij)
    - for all ij not in g, u<sub>i</sub>(g + ij) > u<sub>i</sub>(g) and u<sub>j</sub>(g + ij) <> u<sub>j</sub>(g)
  - No player wants to sever or remove a link and no two players both want to add a link
  - A player has the discretion to unilaterally terminate relationships he's involved in
  - No player gains from severing a link
  - If one player benefits from an added link, another would suffer

- Pairwise stability is necessary but not sufficient for a stable network

- Limitations
  - Considers deviations in a single link at a time
  - Considers deviations by atmost a pair of players, but not a group
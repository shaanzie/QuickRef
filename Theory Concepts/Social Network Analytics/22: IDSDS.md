# Iterated Deletion of Strictly Dominated Strategies

- There are mainly 3 ways of solving strategic games
  - Dominant strategies and dominant strategy equilibrium
  - Dominated strategies and iterative elimination of dominated strategies
  - Nash Equilibrium

- Iterated deletion procedures
  - If in a game a player has a dominant strategy, then the player ought to choose that strategy
  - When there is no dominant strategies, these procedures are used

- IDSDS: The iterated deletion of strictly dominant strategies
  - Given a finite ordinal strategic-form game G
  - Let G1 be the game obtained by removing from G, for every player i, any strictly dominated strategies in G dominated by some other strategy
  - Let G2 be the game obtained by removing from G, for every player i, any strictly dominated strategies in G1 dominated by some other strategy
  - Let G(inf) be the output. Since G is finite, G(inf) will be obtained in a finite amount of steps
    - If G(inf) contains a single strategy profile, then we call it the iterated strict dominant strategy equilibrium, which is a Nash equilibrium
    - If G(inf) contains two or more strategy profiles, we refer to these merely as the output
  - If the players are rational and there is a common belief of rationality then only strategy profiles that survive the IDSDS procedure can be played
# Nash Equilibrium

- Games where either the IDSDS or IWSDS procedure leads to a unique strategy profile are not very common
  - Nash equilibrium offers a more general alternative

- Nash Equilibrium says: even when there are no dominant strategies, we should expect players to use strategies that are best responses to each other
  - If player 1 chooses strategy S and player 2 chooses strategy T, we say this pair of strategies (S, T) is a Nash equilibrium if S is a best response to T, and T is a best response to S

- The idea is if the players choose strategies that are best responses to each other, then no player has an incentive to deviate to an alternative strategy - so the system is in a kind of equilibrium state, with no force pushing it toward a different outcome

- In a Nash equilibrium, every person in a group makes the best decision for herself, based on what she thinks others will do
  - No-one can do better by changing strategy

- Each player is assumed to know the equilibrium and no player has anything to gain by changing only his own strategy

- Definition
  - Given an ordinal game in strategic form with two players, a startegy profile s* = (s1*, s2*) in S1 x S2 is a Nash equilibrium if
    - for every s1 in S1, P1(s1*, s2*) >= P1(s1, s2*) or f(s1*, s2*) >~ f(s1, s2*)
    - for every s2 in S2, P2(s1*, s2*) >= P2(s1*, s2) or f(s1*, s2*) >~ f(s1*, s2)

- There are several possible interpretations of this definition
  - No regret interpretation
    - s is a Nash equilibrium if there is no player who, after observing the opponent's choice, regrets his own choice
  - Self-enforcing agreement interpretation
    - If the players are able to communicate before playing the game and reach a non-binding agreement expressed as a strategy profile s*; then no player will have an incentive to deviate from the agreement, if she believes that the other player will follow the agreement, if and only if s* is a Nash equilibrium
  - Viable recommendation interpretation
    - Imagine a third party makes a public recommendation to each player on what strategy to play, then no player will have an incentive to deviate from the recommendation, if she believes the other players will follow the recommendation, if and only if the recommended strategy profile is a Nash equilibrium
  - Transperancy of reason interpretation
    - If players are all equally rational and player 2 reaches to the conclusion that she should play y, player 1 must be able to duplicate player 2's reasoning and come to the same conclusion

- For a game of n players
  - Given an ordinal game in the strategic form with n players, a strategy profile s* in S is a Nash equilibrium if
    - for every player i, P<sub>i</sub>(s) >= P<sub>i</sub>(s1, .... sn)
  - A weak/strong iterated/non-iterated dominant strategy equilibrium is a Nash equilibrium

- A quick way to find the Nash equilibrium
  - In each column of the table underline the largest payoff of player 1 in that column and in each row underline the largest payoff for player 2
  - If a cell has oth payoffs underlined, then the corresponding strategy profile is a Nash equilibrium
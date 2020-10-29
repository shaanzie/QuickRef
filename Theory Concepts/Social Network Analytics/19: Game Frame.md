# Game Frame

- A game frame is a strategic form is a list of four items
  - <I, (S1, S2, ... Sn), O, f> where
    - I is a set of players with n >= 2
    - S<sub>i</sub> is a set of states for each players, and the set S is called the set of strategy profiles
    - O is a set of outcomes
    - f:S->0 is a functuion that associates with each strategy profile an outcome f(s) = O

- Preferences of ranking
  - o > o' - outcome o is better than outcome o'
  - o ~ o' - outcome o is just as good as outcome o'
  - o >~ o' - outcome o is atleast as good as outcome o'
  - Ranking is complete and transitive

- Ways to represent ranking of outcomes O
  - Ranking as o1 > o2 > o3 > o4 ~ o5 ...
  - By listing outcomes in a column, starting with the best at the top and proceeding down to the worst
  - By assigning a number to each outcome (utility function, higher the index, better the outcome)
    - Given a complete and transitive ranking of a finite states of outcomes O, a function U: O -> R (R is the set of real numbers) is said to be an ordinal utility function that represents the ranking ~> if, for every 2 outcomes o and o', U(o) > U(o') if an only if o > o' and U(o)=U(o') if only o~o'. The number U(o) is called the utility of outcome o

- An ordinal game in strategic form is a quintuple <I, (S1, S2, ... Sn), O, f, (U1, U2, ... Un)> where
  - U denotes the complete and transitive ranking of the set of outcomes O
  - Player's payoff function is P(s) = U(f(s))
  - This gives <I, (S1, S2, ... Sn), (P1, P2, .... Pn)> called a reduced-form ordinal game in strategic form
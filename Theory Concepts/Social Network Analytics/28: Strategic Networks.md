# Strategic Networks

- Games on networks
  - The interaction of individuals who are connected via a network and whose behaviors are influenced by those around them
  - Such interactions are natural to model using game theory such as payoffs
  - A player's payoffs depend on the players who are linked to that player

- The effect of player 1's action on 2's payoff depends on where the two players are located in the network

- A network is a pair (N, g) where g is a network on the set of nodes N
  - Represents interaction structure in a game
  - Indicates the other players whose actions impact a given player's payoff
  - g can be a NxN adjacency matrix or a set of all relationships
  - Adding a link ij is g + ij
  - Deleting is g - ij

- Key features of linkning
  - It is a decision
  - A link between A and B affects payoffs of C as well as rewards for C from linking with A and B

- Key issues in modelling
  - Payoffs : How to allocate
  - Decision power : Who decides on the link
  - Information : Player knows how much information about others

- Strategic Network formation
  - Defines how and why networks take particular forms
  - Relation depends on participants
  - Defines a network's costs and benefits and predicts how individual preferences become outcomes
  - Requires that individuals create relationships that are beneficial and drop those that are not

- Utility function u defines the payoff to a platyer i if network g is in place 

- To model strategic network formation, a network game is used, which is a set of players with utility functions
  - Can be modeled as
    - Extensive form games
    - Simultaneous move games
    - Pairwise stability
    - etc

- Extensive form game
  - PLayers of the network first propose to create links one after the other and make decisions to create a link or not
  - A couple of players decide to either form a link or not by being aware of all the previous players' decisions and by making predictions for the decisions of the following players
  - Representation specifies
    - Players
    - Every opportunity they have to move
    - What each player can do at each move
    - What each player knows about each move
    - The payoffs

- Simultaneous move game modelling
  - All players declare at the same time to whom they want to link
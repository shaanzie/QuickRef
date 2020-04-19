# Lecture 15 - Evaluation of Semantic Rules

- In S-attributed SDDs with a bottom up parser, maintain a value stack with the state stack governed by the same pointer
  - When a reduction occurs, the value stack refers to the reduced symbol's attribute

- In inherited attributes with a top down parser, if all nodes are inherited attributes, it is an L attributed SDDs
  - Evaluated in DFS
  - Order of evaluation is based on when nodes are created
  - For A -> XY...Z, this is L attributed only if each inherited attribute of Z depends only on
    - Attributes of X, Y, ...
    - Inherited attribute of A

- Translation schemes
  - A CFG where semantic actions are in RHS
  - For example, A -> XY { Action } Z is valid, and Action is added as a node in the parse tree
  - We perform depth first order traversal on this tree
  - We ensure inherited attributes are available when required
  - For this, all inherited attributes should come to the left of the nonterminal in the production
  - Synthesized attributes should come where the nonterminal is on the left
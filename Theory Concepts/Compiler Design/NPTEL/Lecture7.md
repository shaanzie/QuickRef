# Lecture 7 - Syntax Analysis

- It is important to know which production to pick up to parse the string
- The context of the non terminal is not considered, as the grammar is a CFG

- Some rules for derivations
  - a A b -> a l b if A -> l is a production
  - If a -> b -> c -> d -> ... -> n, then a -> n
  - Given a grammar G and a string w of terminals in L(G), we can write S -> w
  - If S -> A, and S is a start symbol, these sets are sentential forms of the grammar
  - If in a sentential form, only the leftmost non terminal is replaced, then it becomes a leftmost derivation
  - Similarly, rightmost derivations can be defined
  - An ambiguous derivation is one that produces more than one leftmost/rightmost derivation for the same grammar

- In the parse tree,
  - Root node - start symbol
  - Internal nodes - non-terminals
  - Leaves - terminals

- Ambiguity is handled by
  - Enforce associativity and precedence
  - Rewrite grammar

- 
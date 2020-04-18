# Lecture 13 - LALR(1) parsing and Semantic Analysis

- Lookahead LR parsing groups similar states, with same kernel and different lookaheads, for example, I4 and I7 becomes I47.
- The LALR parse table is the same as SLR, but is more powerful than SLR. It is however, not more powerful than CLR.
- Merging items can result in new conflicts not in LR parsers, but cannot be of shift reduce kind, as LR parsers did not have conflicts
- LALR prasers can have new reduce/reduce conflicts

- Semantic Analysis is used for
  - Check semantics
  - Error reporting
  - Disambiguate operators
  - Type coercion
  - Static checking
    - Type checking 
    - Control flow checking
    - Uniqueness checking
    - Name checks


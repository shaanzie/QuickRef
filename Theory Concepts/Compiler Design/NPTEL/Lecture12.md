# Lecture 12 - LR(1) parsing

- The shift reduce conflict occurs in LR(0) parsers or SLR parsers due to erroneous entries. For example, a symbol can be in the follow set of a non terminal A, but not in the follow set of a character before the non-terminal, or is not in follow of aA.
- So we introduce another symbol to help parsing, and these items are called LR(1) items

- LR(1) = LR(0) with a lookahead symbol

- On LR(1) items, closure is defined as the same as SLR, but appended with the first of the lookahead of the parent.
- For example
```
A -> a.Bb, a
B -> .c, first(Ba)
```

- We construct a Canonical LR Parser(1), which is the most powerful parsing method
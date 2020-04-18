# Lecture 9 - Bottom Up Parsers

- This is a method where parsing begins from the leaf nodes
- The issues here are which substring to match when there are 2 or more substrings that match
- In bottom up parsing, the opposite of rightmost derivation are done
- These are traditionally known as shift reduce parsers
  - The shift action is shifting the dot
  - The reduce is replacing a set of terminals and non-terminals with a non-terminal producing them
- The left of the dot is a set of terminals and non terminals, and the right has only terminals
- This is more powerful
- This class of grammars is called LR() and takes more complexity than LL(1)
- It can handle left recursive grammars and can be used on a variety of languages
- A handle 
  - Is the right hand side of a production
  - Gives a step in the reverse of the rightmost derivation
- If S -> aAw -> abw, b is handle only if A -> b
- Handle pruning: If b is a handle, and A -> b, then replace b by A
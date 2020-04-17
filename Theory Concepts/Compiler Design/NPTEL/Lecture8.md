# Lecture 8 - Parsing

- Predictive parsers can be implemented by maintaining an external stack
  
- A Recursive descent parser has a table where each production with their corresponding nonterminals is represented
  - Considers X the symbol on top of stack, and a is the current symbol
  - $ is a special symbol that defines the termination of an input string
  - if X = a = $, then halt
  - if X = a, but a not equal to $, then pop(X) and increment table pointer
  - if X is a non terminal, then replace X with M[X, a]

- The first of a non-terminal is the first symbol in the nonterminals derivation
- The follow of a non-terminal is the first terminal symbol that follows the non-terminal

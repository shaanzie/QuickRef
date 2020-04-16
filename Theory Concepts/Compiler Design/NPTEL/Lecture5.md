# Lecture 5 - Regular Expressions

- Tokens can be described by regular languages.
- An alphabet is defined over a set of characters, and we say {a} denotes a regular expressions
- The languages representing a regex p are given by L(p).

- Regular definitions are used to define regular expressions in a language
- To build the lexer
  - Write a regular expression for lexemes of each token
  - Construct R matching all lexemes of all tokens
  - Let an input be x
  - If x belongs to L(R) for some rule of R, such that it is the longest rule, and the first rule matched, then it is tokenised based on the rule

- Transition diagrams are used for implementing the regular implementations
  - Set of alphabets
  - Set of states
  - Set of transition states
  - Set of final states
  - Start state
- Transitions from states denote subsequent character reads

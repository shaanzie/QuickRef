# Lecture 6 - Lex overview and Introduction to Syntax Analysis

- Lex works with 4 distinct steps
  - Regular expressions describe the languages that can be recognized by finite automata
  - Translate each token regular expression into an NFA
  - Convert NFA to DFA
  - Minimise DFA
  - Emit code driven by the DFA tables
  
- In the syntax analysis phase we check syntax and construct the abstract syntax tree
- It also performs error reporting and recovery
- It is modeled using CFGs
- We recognize the same with either PDAs or Table Driven Parsers

- Syntax analysis does not handle   
  - Type checking and allowed operations
  - Variable declaration and initialisation

- We move to CFGs because regex cannot articulate more complex strings of tokens
- The CFGs have
  - A set of tokens
  - A set of nonterminals
  - A set of productions 
  - A start symbo

- A grammar derives strings by beginning with a start symbol and repeatedly replaces non-terminals with productions.
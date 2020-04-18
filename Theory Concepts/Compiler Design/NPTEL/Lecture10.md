# Lecture 10 - Conflicts and LR Parsing

- The general shift reduce technique is 
  - If there is no handle on the stack, then shift
  - If there is a handle, then reduce
  
- The conflict occurs when both actions are possible
  - Shift-reduce conflict
  - Reduce-reduce conflict

- LR Parsing contaisn
  - Input
  - Stack contains a string of grammar symbols and states
  - Tables containing action and goto
  - Action is indexed by state and terminal symbols
  - goto table is indexed by state and non-terminal symbols

- The actions in the parser LR
  - Assume S is the top of stack and a is the current symbol
  - Action [S, a]
    - Shift 
    - Reduce
    - Accept
    - Error

- For stack SXMYNZ and input abcde
  - If action[S, a] = shift S then
    - Stack = SXMYNZaS
    - Input = bcde
  - If action[S, a] = reduce A -> b
    - Stack = SXMYNZAP
    - Input = abcde
    - Here, P = goto[S, A]

- State symbols represent the stack contents and the size of the stack is len(tokens) + 1
- Parser state is defined by a DFA state that reads in the stack a
- Accept states are unique reductions

- An augmented grammar defines a new start symbol S' to define that only S' -> S produces an accept state
- a is a viable prefix if 
  - There is a w such that aw is a right sentential form
  - a.w is a configuration of the shift reduce parser
- The set of viable prefixes is a regular language

- The set of LR(0) items are the rules with dot seen in their productions
- The item indicates how much of a viable prefix is seen and how much of the production should be seen

- The closure property specifies that every non-terminal's productions just right to the "." must also be an LR(0) item of that set.
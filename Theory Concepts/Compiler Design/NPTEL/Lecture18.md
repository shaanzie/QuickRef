# Lecture 19 - Type conversion

- Type conversion
  - In an expression x + i where x is real and i is integer
  - Compiler converts both operands to the same type
  - Usually, conversion is to the LHS type
  - May lead to loss of information, so compiler may block

- Overloaded symbols have different meanings depending on context
- Overloading is resolved when a unique meaning is associated with the context of the overload, and that prototype is used for evaluation
- Type resolution
  - try all possible types
  - Keep track of all possible types
  - Discard invalid possibilities
  - Check for single unique type
- Overloading can be resolved in two passes
  - Bottom up : Complete set of all possible types of an expression
  - Top down : Narrow set of possible types based on what could be used in an expression

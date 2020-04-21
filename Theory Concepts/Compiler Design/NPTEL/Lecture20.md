# Lecture 20 - ICG

- Intermediate representations have 2 key features
  - Abstraction at the source level
    - identifiers
    - operators
    - ...
  - Abstraction at the target level
    - Memory locations
    - Register
    - ...

- Code generation is a mapping between source level abstractions and target machine abstractions
- Benefits
  - Retargeting is possible
  - We can do machine independent optimization

- IR should be simple and lightweight with easy expressions of optimizations

- Issues in IR design
  - Code portability and reuse
  - source and target dependencies
  - Whether appropriate for transformations
  - Machine dependency
  - Expressiveness
  - Appropriateness of code optimization and code generation

- High level IR - AST
  - Keeps enough information to reconstruct source form
  - Keeps information about symbol table
  - Natural order of hierarchy
  - DAG is a more complex concise form of the AST

- Three Address Code
  - Sequence of statements of the form X := Y op Z
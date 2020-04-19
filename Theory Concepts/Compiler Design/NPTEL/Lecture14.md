# Lecture 14 - Semantic Analysis

- To create a semantic analyser, we construct an attribute grammar
  - Generalisation of a CFG where each grammar symbol has an associated set of attributes
  - Values of attributes are computed by semantic rules
  - Synthesized attributes: When attributes depend upon the attributes of its children
  - Inherited attributes: When attributes depend upon the attributes of its parent and siblings
  - Syntax directed definition
    - High level specificiation
    - Hides implementation
    - No order of evaluation
  - Syntax directed translation
    - Indicates order of evaluation
    - Some implementation shown
  - Conceptually both are the same
    - Parse input stream
    - Both build a parse tree
    - Traverse tree to infer semantic rules

- Evaluation may
  - Generate code
  - Save info in symbol table
  - Error recovery

- Each grammar production A -> a has associated semantic rules of the form
  - b = f(c1, c2, ... ck)
  - f is a function
  - b is a synthesized attributed of A or
  - b is an inherited attribute of some non-terminal on the right
  - Attribute b depends on c1, c2, ... , ck

- We assume no cyclic dependencies

- Synthesized attributes    
  - A SDD that uses only synthesized attributes is said to be S attributed
  - A parse tree for an S attributed SDD can be annotated by evaluating semantic rules for attributes
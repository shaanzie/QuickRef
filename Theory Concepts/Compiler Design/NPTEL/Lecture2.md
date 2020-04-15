# Lecture 2 - Stages of a Compiler

- Each step in the translation consists of a representation of the source code

- Representations become more specific and come closer to machine level language with each step

- The first few steps - Lexical Analysis
  - First, recognize the set of alphabets available in the language
  - Second, recognize sets of words, such as keywords, identifiers, operators
  - Compilers need to have a set of rules to govern boundaries to inputs for interpretation, governed by the source language
  - In this phase, comments and blank lines are ignored
  - Modeled using regex
  - Generates token streams
  - Recognize FSA for the analyser
  - Error reporting

- In the parsing phase, the input are the lexical tokens which get converted to parse trees to check syntactic integrity
  - Structure analysis
  - Outputs a parse tree
  - Error reporting and recovery
  - Model using CFGs
  - Recognize PDA or Table Driven Parsers

- In the semantic phase, the semantics and the rules of writing a code are checked through the parse tree combined with the context in which those tokens appear
  - Check semantics
  - Report errors
  - Disambiguate overloaded operators
  - Type coercion
  - Static checking
    - Type
    - Control flow
    - Uniqueness
    - Name checks
  - Provides Abstract Syntax Tree

- The parse trees generated should be unique, even if multiple may be possible. The grammar must be disambiguated to provide only one unique parse tree.

- The lexical analysis, the syntax analysis and the semantic analysis are called the frontend, as the information of the code was governed only by the code and not by the underlying machine.

- In optimization, we try to automatically modify programs so that they
  - Run faster
  - Use less resources
  - Some common optimizations
    - Common sub expression elimination - Do not reevaluate computed expressions
    - Copy propogation - Eliminate copies of variables
    - Dead code elimination - Eliminate unreachable code
    - Loop invariance or Code motion
    - Strength reduction - Use a less heavy operator
    - Constant elimination - Eliminate static value operations

- In Code generation
  - Present intermediate representations, and generate machine code from intermediate representations
  - Identify allocation of resources and associated specifications
  - Map identifiers to locations
  - Relocatable addressing for variables
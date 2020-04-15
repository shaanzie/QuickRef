# Lecture 3 - Concluding Introduction

- Information about the tokens is stored in a Symbol Table.
  - Each phase writes some information to this symbol table
  
- The phase structure (Analysis - Synthesis) works because
  - Ensures modularity
  - Platform independent

- Issues in compiler design
  - How to handle erroneous programs
  - Design of programming languages have a big impact on complexity of the compiler
  - M*N vs M+N problem
    - For M languages and N machines, we need M*N compilers
    - We try to find a need to design only M front ends and N back ends, and link all M*N compilers (Universal Intermediate Language)
# Lecture 21 - Symbol Tables and Code Generation

- Compiler uses symbol table to keep track of scope and binding information about names
- Symbol table needs to update names upon new declarations and operations
- All information about a variable is consecutively stored
- To keep records uniform, some information may be stored outside the table
- A name may denote several objects in the same block
  - int x;
  - struct x {float y, z};
  - Record is entered in symbol table only when the role of the variable becomes clear
- Attributes of a name are entered in response to declarations
- Information about storage locations is kept in the symbol table

- In one scope we can have
  - Declarations
  - Expressions, assignments
  - Jumps, iterative or conditional
- Code for functions also will exist
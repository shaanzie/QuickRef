# Introduction to Compilers

## Scope

Compilers translate programs into forms that can be executed by a computer. It can read a program in a <b>source</b> language and translate it into an equivalent program in another <b>target</b> language.

If the target program is an executable machine language program, it can be called by the user to process inputs and produce outputs.

An interpreter is another common kind of language processor. It appears to directly execute the operations specified in the source program on inputs supplied by the user.

The machine language target program is much faster to map inputs to outputs, but the interpreter can give better error diagnostics than a compiler.

## Java Example

Java compiles to bytecodes, which are interpreted by a Java Virtual Machine (JVM). This allows platform-independent code runs.

In order to achieve faster processing of inputs to outputs, some Java compilers, called Just-In-Time (JIT) compilers, translate the bytecodes into machine language immediately before they run the intermediate program to process the input.

## Other Programs

In addition to the compiler, several other programs may be required to create an executable target program.
1. Preprocessor = Collects source program, expands shorthands (macros), into source language.
2. Assembler = Once the compiler takes the preprocessed language, it may compile to assembly code, which is processed by an assembler, that produces relocatable machine code.
3. Linker = Resolves and links relocatable object files with the code.
4. Loader = Puts all executable object files into memory for execution.

## Execution flow

1. Source program
   1. Preprocessor
2. Modified source program
   1. Compiler
3. Target Assembly program
   1. Assembler
4. Relocatable Machine code
   1. Linker/Loader
5. Target Machine code

## Structure of a Compiler

There are two main components of a compiler
1. Analysis
2. Synthesis

### Analysis

Analysis breaks up the source program into constituent pieces and imposes grammatical structure on them. It then uses this structure to create an intermediate representation of the source program.

It processes syntax, and makes a symbol table, which is passed to the synthesis phase. This is called the <b>frontend</b> of the compiler.

### Synthesis

The synthesis constructs the desired target program from the immediate representation and the information from the symbol table. This is called the <b>backend</b> of the compiler.

The compilation process occurs in stages, each of which transforms one representation of a source program to another.

The main phases are
1. Lexical Analyser (takes character stream)
2. Syntax Analyser (takes token stream)
3. Semantic Analyser (takes syntax tree)
4. Intermediate Code Generator (takes syntax tree)
5. Machine Independent Code Optimizer (takes intermediate representation)
6. Code Generator (takes intermediate representation)
7. Machine Dependent Code Optimizer (takes target machine code)

The purpose of the optimization phase is to perform transformations on the intermediate representations, for better target code generation.

## Lexical Analysis

The first phase of the compiler is called lexical analysis or scanning. The lexical analyser groups characters into meaningful sequences called lexemes.
For each lexeme, the analyser produces as output a token in the form <token-name, attribute-value>.

The token name is an abstract symbol, and the attribute value points to the symbol table entry fo the token.

## Syntax Analysis

The second phase is syntax analysis, or parsing, where the first components of the token are used to generate a tree-like intermediate representation that depicts the grammatical structure of a token stream.

## Semantic Analysis

The semantic analyser uses the syntax tree and the information in the symbol table to check the source code for semantic inconsistency with the language definition.

The main part is type checking, where the compiler checks that each operator has matching operands. Some type conversions called coercions may occur, where types are coerced to fit the operands.

## Intermediate Code Generation

Syntax trees are a form of intermediate representation, but they need to be converyed to a lower level and machine-like intermediate representations.

This representation must have 2 important properties:
1. Should be easy to produce
2. Should be easy to translate into the target machine

## Code Optimization

The code generator takes an input an intermediate representation of the source program and maps it into the target language. Assignment of registers is the key to having a good target code generated.

## The Symbol Table

The symbol table is a data structure containing a record for each variable name, with fields for the attributes of the name. It is done to allow fast access of variables to the compiler.

## Grouping of Phases

In the implementation of a compiler, several phases may be grouped together, known as passes.

Some commonly used compiler construction tools are
1. Parser generators - produce automatic syntax analysers from grammar
2. Scanner generators - lexical analysers
3. Syntax-direct translation engines - parse tree APIs and generating intermediate code
4. Code-generator generators - rule based codegen
5. Data flow analysis engines - how values are transmitted from program to program
6. Compiler construction toolkits - constructing various phases of the compiler
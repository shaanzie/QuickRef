# Program Analysis

Program Analysis is the body of work to discover useful facts about programs. Example : gdb. It is broadly classified into 3 kinds
- Dynamic : Execution time (gdb)
- Static : Compiler time 
- Hybrid : Combines dynamic and static

## Dynamic Program Analysis

Some tools to provide dynamic analysis are
- Purify : Array bound checking
- Eraser : Datarace detection
- Valgrind : Memory leak detection
- Daikon : Finding likely invariants

It infer facts of program by monitoring its runs. We can assert possible invariants to be not invariants with just one counter-example, but cannot predict with certainty that a possible invariant <i>is</i> an invariant.

## Static Program Analysis

Infer facts about the program by inspecting its source code.
Some examples are
- Suspicious error patterns : FindBugs, Coverity, Lint
- Memory leak detection : Facebook infer
- Verifying invariants : ESC/JAVA
- Checking API usage rules : Microsoft SLAM

We can assert possible invariants to be not invariants with just one counter-example, but <b>can</b> predict with certainty that a possible invariant <i>is</i> an invariant. This is because static analysis can consider all inputs.

Dynamic execution paths are unsound, which may miss errors. In static execution paths, the analysis is incomplete, where there may be report spurious errors.

If a program analysis is sound and complete, cannot terminate. If it cannot be answered whether a program point reachable on some input, the problem is undecidable.
The three primary consumers of program analysis:
1. Compilers
   - Compilers bridge high level languages with other languages to generate efficient code.
2. Software Quality Tools
   - Tools for testing, debugging and verification
3. IDEs
   - Understand and refractor programs with restructuring

## Different Analysis

- Basic block
- Loop nest
- Intraprocedural
- Inter-procedural
- In-class
- Inter-class
- Control flow
- Data flow
- Dependence
- Alias
- Pointer
- Shape
- Escape
- Taint
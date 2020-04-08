# Some Interesting Questions

## What are the pros and cons of Superscalar Architecture and Very Large Instruction Set Architecture?

| Superscalar                | VLIW                                           |
|----------------------------|------------------------------------------------|
| Dynamic Scheduling         | Static Scheduling                              |
| Complex Hardware           | Simpler Hardware                               |
| Can adapt to variable load | Uses a worst case scheduling                   |
| Compact Code               | Additional NOPs - Waste of space and Bandwidth |

## What is Sun & Ni's Law of Parallelism?

Sun and Ni's law is a memory-bounded speedup model which says that as computing power increases the corresponding increase in problem size is constrained by the system's memory capacity. In general, as a system grows in computational power, the problems run on the system increase in size. 
Sun & Ni's law states that the problem size must scale but be bounded by the memory capacity of the system.

## How can Data Hazards be solved?

1. Data forwarding
2. Synchronization mechanisms
3. Reordering of data - considered volatile
4. False dependency removal

## What is the law of diminishing returns?

The law of diminishing returns states that in production processes, adding more than one factor of production while keeping all other factors constant will at some point result in smaller per unit incremental returns.

## What is a tournament predictor?

Tournament predictors for branch prediction combine both global and local predictors. They use a selector to select the prediction outcome from one of them.

## What is Tomasulo's algorithm for dynamic scheduling?

Tomasulo's algorithm for dynamic scheduling uses register renaming to eliminate output and anti-dependence, as these are just name dependences. It uses reservation stations, which are buffers that fetch and store instruction operands as soon as they are available. Once all source operands are available, the instruction is sent for execution, provided there is no structural hazard.

## What is scoreboarding?

The scoreboard monitors each instruction waiting to be dispatched. Once it determines all the source operands and the required functional units are available, it dispatches the instruction so that it can be executed. However, it is limited as it does not handle WAR and WAW hazards well. 

## What is the difference between dynamic instruction count and static instruction count?

The dynamic instruction count is the actual number of instructions executed by the CPU for a specific program execution, whereas static instruction count is the number of instructions the program has. 

## Parallelise the loop

```
for(i=3; i < N; i++)
{
    a[i] = a[i-3] + c[i];
}
```

## Create a 3-dimensional dependency graph with normalisation.

## Come up with a transformation and explain how it exploits locality.
1. Loop interchange (Column major layout)
```
for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
        A[j][i] += 1;
```

2. Loop fusion
```
for(i = 0; i<n; i++)
    A[i] = B[i] + 5
    C[i] = B[i] + 4
```
3. Loop fission
```
for(i = 0; i<n; i++)
    A[i] = B[i] + 5
for(i = 0; i<m; i++)
    B[i] = B[i-1] + 4
```
4. Loop blocking
```
float A[MAX, MAX], B[MAX, MAX];

for (i=0; i< MAX; i+=block_size) 
{
    for (j=0; j< MAX; j+=block_size) 
    {
        for (ii=i; ii<i+block_size; ii++) 
        {
            for (jj=j; jj<j+block_size; jj++) 
            {
                A[ii,jj] = A[ii,jj] + B[jj, ii];
            }
        }
    }
}

```
5. Loop unrolling
```
for(i = 0; i<15; i+=3)
    a[i] = a[i] + 3;
    a[i + 1] = a[i + 1] + 3;
    a[i + 2] = a[i + 2] + 3; 
```
6. Virtual register allocation
```
```
7. Loop distribution
```
for(i = 0; i<n; i++)
    A[i] = B[i] + 5
for(i = 0; i<m; i++)
    B[i] = B[i-1] + 4
```
8. Scalar Replacement
```
```
10. Loop peeling
```
A[0] += 1
for(i = 1; i<n; i++)
    A[i] += 1;
```

## What will be the point in the iteration space will the GCD exist for a weak SIV test?



## How do MISD examples work?

```

2: j=0
3: PUT(s) 
4: repeat
5:      PUT(1) 
6:      cur=GET() 
7:      PUT(cur.KEY) 
8:      PUT((cur.DATA, 0))
9:      t=GET() 
10:     A = t.KEY.|Adj[u]|
11:     for i=1 to A do
12:         PUT(0) 
13:         PUT(t.KEY,i)
14:         v=GET() 
15:         if v.DATA. f lag == 0 then
16:             PUT(0) 
17:             j= j+1
18:             PUT(j)
19:             PUT(v.KEY) 
20:             PUT(v.KEY,0)
21:             PUT(0,1) 
22:         else
23:             PUT(1)
24:         end if
25:     end for 
26: PUT(1)
27: until GET() = 0 
28: PUT(0)
```

## How much speedup does this loop get with autovectorization?
```
for(int i = 0; i<256; i++)
    a[i] = b[i]*c[i];
```
Aside:  Try making a, b and c byte arrays.

A: 18 times speedup

## The addresses must be aligned to 256 bit boundaries, and if this is not satisfied, there is a performance issues in ARM, but this needs to be checked for x86.

CPU does not read from or write to memory one byte at a time. Instead, CPU accesses memory in 2, 4, 8, 16, or 32 byte chunks at a time. The reason for doing this is the performance - accessing an address on 4-byte or 16-byte boundary is a lot faster than accessing an address on 1-byte boundary.

## Doing Addition is free, in double precision. Why?

 If you are developing for the x86 architecture, and you need extra performance, you might want to look into using the SSE extensions. This can greatly speed up single-precision floating point arithmetic, as the same operation can be performed on multiple data at once, plus there is a separate* bank of registers for the SSE operations. 

## Vectorize this code
```
for(int i = 0; i<N; i++)
{
    if(i%2)
        a[i] = b[i] + c[i];
    else
        a[i] = b[i] - c[i];
}
```
A : Refer to Code Examples

## Create a thread program that prints treads in order of priorities, both ascending and descending. [Extension : Matrix Multiplication (Multithreaded) or Pi calculation]

Refer to thread_concurrency.c in Code Examples.

## Why does the CT increase when the registers are doubled?

## How do you enable and disable SMT?

`/sys/devices/system/cpu/smt/control`

This file lets you enable or disable SMT, and shows its state. There are three values:

on: The CPU supports SMT and it is enabled. All logical CPUs can be taken offline or online without restriction.
off: The CPU supports SMT but it is disabled. Only so-called primary SMT threads can be taken offline/online without restriction. Attempts to put a non-primary sibling thread online will be rejected.
notsupported: The CPU does not support SMT. You will not be able to write to the control file.


## Are there cases where SMT should be disabled?

## What are the overheads of invalidation based cache coherence protocol?

## How can you set the affinities of multi-threading?

## Give some examples of
1. ILP
```
load R1 <- R2
add R3 <- R3, 1
add R4 <- R4, R2
add R3 <- R3, 1
add R4 <- R3, R2
```
2. DLP
```
func1(data[0:100])
func1(data[100:300])
with no data dependency
```
3. TLP
```
thread1(func1)
thread2(func2)
```
4. PLP (Pipeline level parallelism)
```
Execute different pipelines in different stages by setting up buffers
```
5. LLP (Loop level parallelism)
```
for(int i = 0; i<N; i++)
{
    a[i] = b[i] + c[i]
}
```

## What are precise exceptions and speculation?

## Research about Purify, Eraser, Valgrind, Daikon.

### Purify

Purify is a tool that can help you find logical errors in your program that lead to:
1. bad array indexes
2. bad pointer dereferences (e.g., deferencing an uninitialized pointer
3. dereferencing a NULL pointer, or dereferencing a dangling pointer)
storage leaks

Purify works by instrumenting your code, adding runtime checks for bad memory accesses and storage leaks. When you run the instrumented program, a new purify window is opened; if your program performs any 

### Eraser

Eraser approaches locks by defining a set C(v) of candidate locks which might be used to protect a given shared variable. This set is defined as all possible locks, immediately after initialization (or as close as they can get - the authors admit they have no direct mechanism to detect init completion), and refined to smaller sets of locks as the shared variable is used. If a shared variable is ever accessed without any locks whatsoever, for example, C(v) for that variable is set to [] and remains the empty set until the end of execution.

### Valgrind

The Valgrind tool suite provides a number of debugging and profiling tools that help you make your programs faster and more correct. The most popular of these tools is called Memcheck. It can detect many memory-related errors that are common in C and C++ programs and that can lead to crashes and unpredictable behaviour.

### Daikon

Daikon is an implementation of dynamic detection of likely invariants; that is, the Daikon invariant detector reports likely program invariants. An invariant is a property that holds at a certain point or points in a program; these are often seen in assert statements, documentation, and formal specifications.

### Atom

ATOM (Analysis Tools with OM) is a single framework for
building a wide range of customized program analysis tools.
It provides the common infrastructure present in all codeinstrumenting tools; this is the difficult and time-consuming
part. The user simply defines the tool-specific details in
instrumentation and analysis routines. Building a basic block
counting tool like Pixie with ATOM requires only a page of
code.

### PIN

Pin is a dynamic binary instrumentation framework for the IA-32, x86-64 and MIC instruction-set architectures that enables the creation of dynamic program analysis tools. Pin provides a rich API that abstracts away the underlying instruction-set idiosyncrasies and allows context information such as register contents to be passed to the injected code as parameters. Pin automatically saves and restores the registers that are overwritten by the injected code so the application continues to work. Limited access to symbol and debug information is available as well.

### Fasttrack



### Roadrunner

ROADRUNNER is a dynamic analysis framework designed to facilitate rapid prototyping and experimentation with dynamic analyses
for concurrent Java programs. It provides a clean API for communicating an event stream to back-end analyses, where each event
describes some operation of interest performed by the target program, such as accessing memory, synchronizing on a lock, forking
a new thread, and so on.

### Lint

Linting is the automated checking of your source code for programmatic and stylistic errors. This is done by using a lint tool (otherwise known as linter). A lint tool is a basic static code analyzer.

### perflint

Simply by recompiling and running on a representative input set, programmers receive context sensitive performance advice on their use of standard library data structures and algorithms. Our solution consists of collecting traces of relevant library operations and state during program execution, and then recognizing patterns for which there is a faster alternative, based on a model made of performance guarantees in the C++ language standard and machine knowledge. perflint has already found hundreds of suboptimal patterns in a set of large C++ benchmarks.

### FindBugs

FindBugs™ is a program to find bugs in Java programs. It looks for instances of "bug patterns" --- code instances that are likely to be errors.

### Coverity

Additionally, Synopsys's implementation of static analysis can follow all the possible paths of execution through source code (including interprocedurally) and find defects and vulnerabilities caused by the conjunction of statements that are not errors independent of each other.

### Microsoft SLAM

SLAM is a project for checking that software satisfies critical behavioral properties of the interfaces it uses and to aid software engineers in designing interfaces and software that ensure reliable and correct functioning. Static Driver Verifier is a tool in the Windows Driver Development Kit that uses the SLAM verification engine.

### Facebook infer

SLAM is a project for checking that software satisfies critical behavioral properties of the interfaces it uses and to aid software engineers in designing interfaces and software that ensure reliable and correct functioning. Static Driver Verifier is a tool in the Windows Driver Development Kit that uses the SLAM verification engine.

### ESC/Java

ESC/Java (and more recently ESC/Java2), the "Extended Static Checker for Java," is a programming tool that attempts to find common run-time errors in Java programs at compile time.[1] The underlying approach used in ESC/Java is referred to as extended static checking, which is a collective name referring to a range of techniques for statically checking the correctness of various program constraints.

### Soot

In static program analysis, Soot is a bytecode manipulation and optimization framework consisting of intermediate languages for Java. It has been developed by the Sable Research Group at McGill University. Soot provides four intermediate representations for use through its API for other analysis programs to access and build upon:

## What are the different types of memory errors?

- Dereferencing a null pointer, which usually points to an address that's not part of the process's address space
- Dereferencing or assigning to an uninitialized pointer (wild pointer, which points to a random memory address)
  - Allocator may not return the memory back to OS, causing no errors.
- Dereferencing or assigning to a freed pointer (dangling pointer, which points to memory that has been freed/deallocated/deleted)
- A buffer overflow
- A stack overflow
- Attempting to execute a program that does not compile correctly. (Some compilers will output an executable file despite the presence of compile-time errors.)

## What are the different kinds of problems with locks with examples?

1. Wrong locks acquired (Race conditions)
2. Deadlocks
3. Lock not being acquired (Race conditions)
4. Lock not being freed (Starvation)
5. Livelocks : A Livelock is a situation where a request for an exclusive lock is denied repeatedly, as many overlapping shared locks keep on interfering each other.

## What are assertions and why are they used?

Assertions are used for writing bulletproof and stringent code. This is mainly done for unit testing. 

## What is a sound, precise and complete analysis?

## What are DUchains and UDchians?

## What are available expressions, live variables?

## What do the following mean?

1. Static Program Analysis
   1. Static program analysis is the analysis of computer software that is performed without actually executing programs, in contrast with dynamic analysis, which is analysis performed on programs while they are executing. In most cases the analysis is performed on some version of the source code, and in the other cases, some form of the object code.
2. Dynamic  Program Analysis
   1. Dynamic program analysis is the analysis of computer software that is performed by executing programs on a real or virtual processor. For dynamic program analysis to be effective, the target program must be executed with sufficient test inputs to cover almost all possible outputs.
3. Hybrid Program  Analysis
   1. Mixture of dynamic and static program analysis
4. Abstract Interpretation
   1. Most interesting properties of programs are undecidable, and even those that are not may be very expensive to compute. Therefore, static analysis usually involves some kind of abstraction. For example, instead of keeping track of all of the values that a variable may have at each point in a program, we might only keep track of whether a variable's value is positive, negative, zero, or unknown. Abstraction makes it possible to discover interesting properties of programs, but the results of static analysis are usually incomplete: for example, an analysis may say that a variable's value is unknown at a point when in fact the value will always be positive at that point.
5. Model Checking
   1. Model checking is a method for formally verifying finite-state concurrent systems. Specifications about the system are expressed as temporal logic formulas, and efficient symbolic algorithms are used to traverse the model defined by the system and check if the specification holds or not. Extremely large state-spaces can often be traversed in minutes. The technique has been applied to several complex industrial systems such as the Futurebus+ and the PCI local bus protocols.
6. Concurrency Bugs
   1. A concurrency bug is an (undesired) outcome that arises if two programs are run at the same time that does not show up if the two programs are run sequentially, one after the other. 
7. Performance Bugs
   1. Performance issues are introduced by mistake and “unintended behavior”, the very definition of a bug. If the product is a performance based one and it's having performance requirements, the performance issues should be treat like blocker bugs.
8. Memory Bugs
   1. Memory bugs, essentially a mistake in the management of heap memory, can occur in any program that is being written, enhanced, or maintained.
9.  Basic Block Analysis
    1.  At the end of the BB analysis each instruction in I must be either reached, unreachable, leader, or unreachable leader. The purpose of unreachable leaders is explained below. Unreachable code can be eliminated from I.
10. Loop Nest Analysis
    1.  Dependence Analysis
11. Intraprocedural Analysis
    1. Intraprocedural analysis is a mechanism for performing optimization for each function within a compilation unit, using only the information available for that function and compilation unit.
12. Inter-Procedure Analysis
    1. Interprocedural analysis is a mechanism for performing optimization across function boundaries. The optimizing translator performs interprocedural analysis, but only within a compilation unit.
13. In-class analysis
    1.  
14. Inter-class Analysis
15. Control Flow Analysis
    1. In computer science, control-flow analysis (CFA) is a static-code-analysis technique for determining the control flow of a program. The control flow is expressed as a control-flow graph (CFG). 
16. Data Flow Analysis
    1.  Dataflow analysis is usually performed on the program's control-flow graph (CFG); the goal is to associate with each program component (each node of the CFG) information that is guaranteed to hold at that point on all executions.
    ```
    a = 1;
    b = 2;
    c = 3;
    if (...) x = a + 5;
    else x = b + 4;
    c = x + 1;
    ```
    1. In this example, the initial assignment to c (at line 3) is useless, and the expression x + 1 can be simplified to 7, but it is less obvious how a compiler can discover these facts since they cannot be discovered by looking only at one or two consecutive statements. 
17. Dependence Analysis
    1.  In compiler theory, dependence analysis produces execution-order constraints between statements/instructions. Broadly speaking, a statement S2 depends on S1 if S1 must be executed before S2. Broadly, there are two classes of dependencies--control dependencies and data dependencies. Dependence analysis determines whether it is safe to reorder or parallelize statements.
18. Alias Analysis
    1.  Alias analysis is a technique in compiler theory, used to determine if a storage location may be accessed in more than one way. Two pointers are said to be aliased if they point to the same location.
19. Pointer Analysis
    1. In computer science, pointer analysis, or points-to analysis, is a static code analysis technique that establishes which pointers, or heap references, can point to which variables, or storage locations. It is often a component of more complex analyses such as escape analysis. A closely related technique is shape analysis.
20. Shape Analysis
    1.  In program analysis, shape analysis is a static code analysis technique that discovers and verifies properties of linked, dynamically allocated data structures in (usually imperative) computer programs. It is typically used at compile time to find software bugs or to verify high-level correctness properties of programs.
21. Escape analysis
    1. In compiler optimization, escape analysis is a method for determining the dynamic scope of pointers – where in the program a pointer can be accessed. It is related to pointer analysis and shape analysis.
22. Taint Analysis
    1. The taint analysis is a popular method which consists to check which variables can be modified by the user input. All user input can be dangerous if they aren't properly checked. 
23. Compiler Optimization
    1. In computing, an optimizing compiler is a compiler that tries to minimize or maximize some attributes of an executable computer program. Common requirements are to minimize a program's execution time, memory requirement, and power consumption (the last two being popular for portable computers).
24. Loop Optimization (LNO)
    1.  In computer science and particularly in compiler design, loop nest optimization (LNO) is an optimization technique that applies a set of loop transformations for the purpose of locality optimization or parallelization or other loop overhead reduction of the loop nests. One classical usage is to reduce memory access latency or the cache bandwidth necessary due to cache reuse for some common linear algebra algorithms.
25. Link Time Optimization (LTO)
    1.  Link Time Optimization (LTO) refers to program optimization during linking. The linker pulls all object files together and combines them into one program.
26. Whole Program Analysis

## What gets printed?
```
Thread 1

A = 1
if(B == 0)
    print "Hello";

Thread 2

B = 1
if(A == 0)
    print "World";
```
1. Assume A and B are intialised to 0, and are run simultaneously on a two processor system.
2. What if the write was not atomic?

Ans: 

1.
```
Hello
World
HelloWorld
WorldHello
<nothing>
```

## What orderings can occur when a racey program is given, depending on the architecture (based on consistency model)?

## What different consistency models are followed in real processors?

## Give an example of priority inversion and how do you prevent it? When does the prevention occur?

https://stackoverflow.com/questions/4252158/what-is-priority-inversion

Priority inversion can be avoided by avoiding blocking as the low priority task blocks the high priority task. The priority of the ready tasks can be randomly boosted until they exit the critical section.

## What is async-signal-safety?

## Implement skip-lists (Serial and Parallel).

## Implement Computer Vision Algorithms using Intel TBB.

## When is OpenMP better than TBB?

## Do vector addition using OpenCL.

## Why is the tradeoff for speed is easier comparitively for a GPU?

This is because the design is not as complex.

## Can we do pipeline parallelism in OpenCL?

## Compute a[i] = b[i]*c[i] + d[i]*e[i] on OpenCL, CUDA and compare performance. ( n varies from 100000 to 1000000).

## Write matrix mult for C++AMP.

## Use async in C++11 to code sum of squares from 1 to 20.
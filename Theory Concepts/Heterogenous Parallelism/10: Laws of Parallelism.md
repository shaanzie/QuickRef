# Laws of Parallelism

## Moore's Law

Moore's law states that the number of transistors in an integrated circuit doubles every 18-24 months. In short, the density of transistors doubles every 18-24 months.
Moore's law has benefitted in the following introductions
1. Caches
2. Pipelining
   1. Overlapping of instructions
3. Branch prediction
   1. The challenges in branch prediction are
      1. User input handling
      2. Complex hardware
      3. Capturing past behavior
      4. Branch correlations modeled with history
4. Multiple Issues
   1. Multiple pipelines can exist, such as integer, floating point, replicated, etc
5. Out of order Issues / Dynamic Scheduling
6. Larger register files
7. Superscalar / VLIW
8. Register Allocation
9.  Vectorization
10. Prefetching
    1. Caching does not leverage irregular memory accesses in locality, so we prefetch data which may be used to the cache
11. Speculation
    1.  Control speculation and Data speculation
12. Instruction scheduling
13. Software pipelining
    1.  Allows optimization techniques such as overlapping instructions at the software level

Moore's law has suffocated when it encountered
1. Power Wall - Heat dissipation increased
2. Memory Wall - Memory cannot keep up with CPU performance
3. Frequency Wall - Frequency bottleneck
4. Engineering Wall - New innovations to keep up with density

Golden equation of performance is `Execution Time = IC x CPI x CT`.

Due to the existence of these software walls, new processors offer
1. Multiple heterogeneous cores
2. CPUs
3. GPUs
4. GPGPUs
5. Fusions of CPUs and GPUs
6. Accelarators / Reconfigurable Hardware
7. Putting multiples of this on the same chip

CPUs are designed to optimize latency (Time taken for execution). They have
1. High clock frequency
2. Large caches
   1. Convert long latency memory accesses to short latency cache accesses
3. Sophisticared control
   1. Branch prediction for reducing branch latency
   2. Data forwarding for reduced data latency
4. ALU optimized
   1. Reduced operation latency

GPUs have a throughput oriented design, where they exploit fine grained parallelism
1. Moderate clock frequency
2. Small caches
3. Energy efficient ALUs
4. Simple Control
   1. No branch prediction, data forwarding
   2. Performance decreased when code is divergent
5. Require massive number of threads to tolerate latency
   1. Synchronous, degrade performance

## Amdahl's Law

If F is the fraction of a calculation that is sequential, and (1 - F) is the fraction that can be parallelised, then the maximum speedup that can be achieved using P processors is 
```
S = 1 / ( F  + (1 - F)/P )
```
The number of parallel processors used is constrained by the amount of time that the program is in a sequential stage. The performance bottleneck occurs at the slowest instruction. The actual speedup is always lesser than the predicted speedup, and this law works in the environment where the problem size is fixed. 

Extra work is involved in
1. Work distribution in  parallel processors and result collection
2. Straggler probem : Different compute times for different processors.

## Gustafson's Law

```
S(n) = a + (1 - a)n 
```
The speedup over a single processor is given by a which is the workload to be scaled up and  n is the number of processors. If the number increases, there will always be a net speedup increase, regardless of the application. The slope however, may change with the application.

## Parallel Programming Workflow

1. Identify compute internsive parts of an application
2. Adopt scalable algorithms
3. Optimize data arrangements to maximise locality
4. Performance tuning
5. Pay attention to code portability, scalability and maintainability


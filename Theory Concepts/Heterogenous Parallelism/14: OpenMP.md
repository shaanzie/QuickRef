# Introduction to Parallel Computing with OpenMP

## Moore's Law

- Forecasts that the transistor density doubles every 18-24 months
- Performance doubling with the number of transistors
- Trained people to expect that performance comes from hardware
- Optimization is pushing compute to the hardware
- Optimization hit a power wall, where power increases with optimized compute
- Unsustainable growth in power
- This led to redesign the architecture for power, and the number of pipeline stages were simplified
- This allows the architecture to get a power consumption point
- The power scales with the circuits capacity, as q = CV. Work = Vq and this gives W = CV<sup>2</sub>
- Power is CV<sup>2</sup>F
- This led to the design of parallel architectures, by connecting processors in a parallel configuration, allowing half the frequency at the same voltage, giving the same output as a single core machine, but with more throughput.
- <b>Performance comes from software. The Free Lunch is Over</b>.
- Automatic parallelism has failed, so needs to be done on the software side.

## Parallel Computing

- Concurrency is a condition where multiple components make progress simultaneously
- Parallelism is components working simultaneously
- Expose the concurrency to a set of parallel processor to enforce parallelism
- Parallel applications can be written serially, and be run to enforce parallel execution
- OpenMP is an API to write multithreaded applications, with compiler directives and library routines.
- The solution stack is
  - HW: Shared address space hardware
  - System layer: The openMP runtime library with OS/System support for shared memory and multithreading
  - Programming layer
  - End user
- The core syntax is `#pragma omp construct [clause[clause....]]`.
- Most OpenMP constructs apply to a structured block, which is a block of one or more statements with one entry and one exit only.

## Simple Threading

- OpenMP assumes shared memory computers
- Symmetric Multiprocessor : Shared processor with equal memory access time, and all processors are identical.
- NUMA or Non Uniform Address Space Multiprocessors do not have uniform memory access time
- A process is an instance of program execution. The context is the resources associated with a process.
- These processes are divided in threads by fragmenting the stack and providing new registers and a program counter per thread, with low context switch times.
- Interleaving should be done in a way that the program, upon multiple runs gives a coherent and correct output.
- Synchronization is done to ensure no data races, but is very expensive, so it must be done carefully.

## OpenMP constructs

- Uses the fork-join parallelism model
- Program starts as a single thread, and then additional threads are forked from the master thread to a parallel region of execution, and joins back to the master when the execution is done
- Threads can be nested in the parallel region as well.
- Compiler generates a thunk() function that sets up the pthread environment running the copy of the function, and after running, it will call thunk itself.

## Synchronization

- Barrier
  - Each thread waits at the barrier until all the threads arrive
- Mutual Exclusion
  - Define a block of code that only one thread at a time can execute
- High Level Sync
  - Critical
  - Atomic 
  - Barrier
  - Ordered
- Low Level Sync
  - Flush
  - Locks

1. Barrier synchronization

```
#pragma omp parallel
{
  int id = omp_get_thread_num();
  A[id] = some_big(id, A);
  #pragma omp barrier
  B[id] = some_big(id, A);
}
```

2. Mutual Exclusion - Critical Section

```
float res;
#pragma omp parallel
{
  float B;
  int id, i, nthrds;
  id = omp_get_thread_num();
  nthrds = omp_get_num_threads();
  for(i = id; i<niters; i+=nthrds) {
    B = big_job();
    #pragma omp critical
    {
      res += consume(B);
    }
  }
}
```

3. Atomic

- There are constructs in hardware that do quick updates in memory and these need efficient mutual exclusion. Atomic says that if there exists such optimizations, use them. 

```
#pragma omp parallel
{
  double tmp, B;
  B = DOIT();
  tmp = big_ugly(B);

  #pragma omp atomic
  {
    X += tmp;
  }
}
```
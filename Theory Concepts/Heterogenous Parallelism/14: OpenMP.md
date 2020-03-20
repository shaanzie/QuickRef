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

- Worksharing is used to divide work among threads.
- The most common worksharing construct is loop.

```
#pragma omp parallel
{
  #pragma omp for
  for(i = 0; i<N; i++)
  {
    NEAT_STUFF();
  }
}
```
- This splits up the iterations of this to each thread.
- OpenMP makes the loop control index on a parallel loop private to a thread
- The `schedule` directive tells the compiler how to split the iterations
  - `schedule(static [,chunk])` deals out blocks of iterations of size chunk to each thread
  - `schedule(dynamic [,chunk])` is used when each thread grabs a chunk of iterations off a queue
  - `schedule(guided [,chunk])` is where threads dynamically grabs blocks of iterations and the size shrinks as the calculation proceeds
  - `schedule(runtime)` is where the OMP_SCHEDULE env variable takes the schedule and chunk size
  - `schedule(auto)` is where the schedule is left upto the runtime to choose

- We use the static clause when the decision is predetermined and predictable, and allows the least work at runtime.

- There are times where barriers need to be declared explicitly, and times where barriers are implicitly introduced in the code

```
#pragma omp parallel shared (A, B, C) private(id)
{
  id = omp_get_thread_num();
  A[id] = big_calc(id);
  #pragma omp barrier
  #pragma omp for
    for(i = 0; i<N; i++) {  C[i] = big_calc3(i, A); }
  #pragma omp for nowait
    for(i = 0; i<N; i++) {  B[i] = big_calc2(C, i); }
    A[id] = big_calc4(id);
}
```

- In this, A, B and C are shared and id is private
- Here, an explicit barrier is used to specify that A should be done updating for the next clause
- But there exists an implicit barrier at the end of the loop, to produce safety.
- There exists an implicit barrier for every worksharing construct
- In the third loop, a barrier is not required as B is not affected by calculations of C. Hence, the nowait clause is used to turn off barriers, and must be used carefully
- The master construct says that only the master thread is allowed to execute the block of code specified in the master

```
#pragma omp parallel
{
  do_many();
  #pragma omp master
  {
    exchange_boundaries();
  }
  #pragma omp barrier
}
```

- The single worksharing construct is used to specify that only one thread does the work in this block.
- Single attaches an implicit barrier at the end of the construct

```
#pragma omp parallel
{
  do_many();
  #pragma omp single
  {
    exchange_bounds();
  }
}
```

- The sections and section constructs give a way to execute sections of code.

```
#pragma omp parallel
{
  #pragma omp sections
  {
    #pragma omp section
      x_calculation();
    #pragma omp setion
      y_calculation();
    #pragma omp section
      z_calculation();
  }
}
```

## Locks in OpenMP

- Locks are the lowest level of synchronization
- omp_init_lock() - Initialises lock
- omp_set_lock() - Sets a lock
- omp_unset_lock() - releases a lock
- omp_destroy_lock() - destroys a lock
- omp_test_lock() - If lock is available, set, else returns not available and the thread can do something else
-  
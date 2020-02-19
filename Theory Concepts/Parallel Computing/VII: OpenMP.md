# OpenMP

OpenMP is an API to writing multithreaded applications. It consists of a set of compiler directives and library routines for parallel application programmers, simplifying multithreaded programs. The solution stack broadly consists of
1. User layer
   1. End user and application
2. Programming layer
   1. Directives, libraries, environment variables
3. System layer
   1. OpenMP runtime library
   2. OS support for threads
4. Hardware

Most of the constructs in OpenMP are compiler directives of the form
```
#pragma omp construct [clause[clause]...]
```
The prototypes of the functions can be found in omp.h. Most of these constructs apply to a strucutred block, which is a block of one or more statements with one point of entry at the top and one point of exit in the bottom.

Threads in openMP communicate by sharing variables. This may cause data races. To control these, synchronization needs to be done to prevent data conflicts. Since synchronization is expensive, we change how the data is accessed so that it is minimised.

## The OpenMP Programming Model

OpenMP uses fork-join parallelism where the master thread spawns as many threads as needed, and parallelism is added incrementally until performance goals are met.

Thread creation is done by using `omp_set_num_threads(<number>)`. At runtime, `omp_get_thread_num()` returns the thread ID of the thread executing that block of the code. Each thread executes a copy of the code in its own block. Thread creation can also be done in the directive definition as `#pragma omp parallel num_threads(<number>)`.

Once the threads are set for execution, the threads wait for all threads to finish before proceeding, that is, they create a barrier. 

## Synchronization

Synchronization is used to impose order constraints and protect access to shared data. This can be done in two ways
1. High Level
   1. critical
   2. atomic
   3. barrier
   4. ordered
2. Low Level
   1. flush
   2. locks - simple and nested

Critical synchronization is achieved by mutexes, where only one thread can enter a critical section at a time. This is done by encapsulating the block in `#pragma omp critical`.

Atomic synchronization provides mutual exclusion but only applied to the update of a memory location. This is done by encapsulating the block in `#pragma omp atomic`.
False sharing is when array elements appear to share a cache line. Non shared data is in the same line so each update invalidates the cache line.

A barrier is when each thread waits until all the threads arrive. Worksharing and parallel constructs have an implicit barrier, but for other cases, it can be specified by `#pragma omp barrier`.

The master construct denotes a structured block only to be executed by the master thread, and the other threads just skip it. This is specified by `#pragma omp master`.

The single construct denotes a block of code that is executed by only one thread, which need not be the master. A barrier is hence, implied at the end of a single block. This barrier can be removed with `#pragma omp nowait`. The single construct is defined by `#pragma omp single`.

Ordered synchronization executes the ordered region in sequential order. This is specified by `#pragma ordered` and can be added to for and reduction clauses.

OpenMP provides simple lock routines, where a simple lock is available if it is unset. It gives APIs such as
1. omp_init_lock()
2. omp_set_lock()
3. omp_unset_lock()
4. omp_test_lock()
5. omp_destroy_lock()

Nested locks are available if they are uset or if they are set but owned by the thread executing the nested lock function.
1. omp_init_nest_lock()
2. omp_set_nest_lock()
3. omp_unset_nest_lock()
4. omp_test_nest_lock()
5. omp_destroy_nest_lock()

A flush defines a sequence point at which a thread is guaranteed to see a consistent view of memory with respect to a flush set. The flush set is
1. All thread visible variables for a flush construct without an argument list
2. A list of variables when the flush(list) construct is used.

The action of flush is to guarantee that
1. All RW ops that overlap the flush set and occur prior to the flush complete before flush
2. All RW ops that overlap the flush set and occur after the flush execute only after the flush
3. Flushes with overlapping flush sets cannot be reordered.

## Parallel Loops

A parallel construct creates an SPMD program, where each thread redundantly executes the same code. To make pathways between threads, called worksharing, we use
1. Loop constructs
2. Sections construct
3. Single construct
4. Task construct

The loop worksharing construct splits up the loop iterations among the threads in a team. This is done by encapsulating the loop in `#pragma omp for`. The iteration variable is made private to each thread block. We can combine the parallel and worksharing construct as `#pragma omp parallel for`. The basic approach is
1. Find compute intensive loops
2. Make the iterations independent
3. Place the appropriate OMP directive

In some cases, there may exist a true dependency in the loop, called reduction. The OpenMP reduction clause is `reduction (op : list)`. Inside a parallel or a worksharing construct,
1. A local copy of each list variable is made and initialised based on the op
2. Compiler finds standard reduction expressions to update the local copy
3. Local copy reduced to a single value and combined with global values..

For example,
```
double ave = 0.0, A[MAX];
int i;
#pragma omp parallel for reduction (+:ave)
for(i = 0; i<MAX; i++) {
    ave += A[i];
}
ave = ave/MAX;
```

Some other runtime library options are
1. Modify/Check number of threads
   1. omp_set_num_threads()
   2. omp_get_num_threads()
   3. omp_get_thread_num()
   4. omp_get_max_threads()
2. Check if we are in an active parallel region
   1. omp_in_parallel()
3. Want the system to dynamically vary number of threads from one parallel construct to another
   1. omp_set_dynamic()
   2. omp_get_dynamic()
4. How many processors 
   1. omp_num_procs()

For example, to use a fixed number of threads,
```
omp_set_dynamic(0);
omp_set_num_threads (omp_num_procs());
```

Some environment variables include
1. Default number of threads - OMP_NUM_THREADS
2. How many omp for schedule(RUNTIME) loop iterations are scheduled - OMP_SCHEDULE "schedule[, chunk_size]"

## Data Environment

Default storage attributes include
1. Shared memory model where most variables are shared
2. Global variables are shared among threads
3. Stack variables and auto variables in a block are private

These storage attributes can be changed using the clauses
1. SHARED
2. PRIVATE
   1. Creates a new local copy for each thread
   2. `#pragma omp for private(var)`
   3. The original variables value is unspecified
3. FIRSTPRIVATE
   1. Initialises each private copy with the corresponding value from the master thread
4. LASTPRIVATE
   1. The final value of a private inside a parallel loop can be transmitted to the shared variable outside the loop with LASTPRIVATE. 

All the clauses apply to parallel and worksharing constructs except for shared, which applies to parallel constructs. The DEFAULT clause is used to change the default data sharing. DEFAULT(NONE) provides no default for variables in a static extent, and listing storage values for each variable in a static extent is a good practice.

The default for `#pragma omp task` is usually firstprivate, because the task may not be executed until later. 

Threadprivate makes global data private to a thread. With private, global variables are masked. THREADPRIVATE preserves global scope within each thread. These can be initialised using COPYIN at the time of definition.

Copyprivate is used with a single region to broadcast values of privates from one member of a team to the rest of the team. 

## Scheduling for and sections

The sections worksharing construct gives a different structured block to each thread. This is defined by `#pragma omp sections`. Inside the sections clause, there are multiple `#pragma omp section` clauses defining independent sections.

The schedule clause affects how loop iterations are mapped onto threads
1. schedule(static[,chunk])
   1. Deal out blocks of iterations of size "chunk" to each thread
   2. Predetermined and predictable by programmer
2. schedule(dynamic[,chunk])
   1. Each thread grabs "chunk" iterations off a queue till all iterations are assigned
   2. Highly variable work
3. schedule(guided[,chunk])
   1. Threads dynamically grab blocks of iterations, and the size decreases
   2. Special case of dynamic with lesser overhead
4. schedule(runtime)
   1. Schedule and chunk size taken from OMP_SCHEDULE at runtime

## Memory Model

OpenMP supports a shared memory model. All threads share an address space, and the model is defined on coherence(behavior of multiple access) and consistency(order). The compiler reorders program order to code order in reordering and the machine reorders code order to the memory commit order.

Consistency can be 
1. Sequential
   1. ops(R, W, S) are sequentially consistent if
      1. They remain in program order for each processor
      2. They are in the same overall order
   2. Program order = code order = commit order
2. Relaxed consistency
   1. Remove some of the ordering constraints from sequential
   2. S ops must be sequential and R and W ops cannot be used to reorder S on the same thread
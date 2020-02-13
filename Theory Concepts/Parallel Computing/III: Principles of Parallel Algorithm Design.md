# Principles of Parallel Algorithm Design

In practice, a non trivial parallel algorithm must have the following
1. Identifying portions of work to be performed concurrently
2. Mapping the concurrent pieces of work onto multiple processes running in parallel
3. Distributing input, output and intermediate data associated with the program
4. Managing accesses to data shared by multiple processors
5. Sync processors at various stages of executions

## Preliminaries

Dividing a computation into smaller computations and assigning them to different processors is the essence of parallel computing.

### Decomposition, Tasks and Dependency Graphs

The process of dividing a computation into smaller parts to execute some of them or most of them in parallel, is called decomposition.

Tasks are programmer defined units of computation into which the main computation is subdivided by means of decomposition.

Some tasks may depend on the output of other tasks, and the abstraction used to denote these dependencies is called a task-dependency graph. This graph is a DAG in which the nodes represent the tasks and the directed edges the dependencies between them.

### Granularity, Concurrency and Task Interaction

The number and size of tasks into which a problem is decomposed determines the granularity of the decomposition. Large numbers of small tasks is fine grained and small numbers of large tasks is coarse grained.

The maximum degree of concurrency is the maximum amount of tasks that can be executed simultaenously in a parallel program at any time. The average however, is a better measure of performance.

The longest directed path between any pair of start and finish nodes in a dependency graph is called the critical path, and the sum of the weights along this path is known as the critical path length.

The ratio of the total amount of work to the critical path length gives the degree of concurrency.

Fine-grained parallelism has a bound on how much decomposition can be done. The interaction is another factor to limit parallelism where a task can be dependent on other tasks.

The interaction between tasks is captured in a task-interaction graph. Weights can be assigned by the amount of compute handled.

### Processes and Mapping

The mechanism by which tasks are assigned to processes is called mapping. A good mapping seeks to maximise the use of concurrency by mapping independent tasks onto different processes, and maximises total completion time by minimising interactions.

### Processes vs Processors

Processes are logical computing agents that perform tasks. Processors are the hardware units that physically perform computations.

## Decomposition Techniques

Decomposition techniques are broadly classified into
1. Recursive decomposition
2. Data decomposition
3. Exploratory decomposition
4. Speculative decomposition

### Recursive Decomposition

This uses the divide and conquer strategy, by decomposing the problem into a set of subproblems, which are solved recursively.
Example: Quicksort.

### Data Decomposition

Two steps
1. Data is partitioned 
2. Data partioning is used to induce partitioning of computations

There are many ways to partition the data
1. Partitioning output data
   1. Output element can be calculated independently as a function of the input. Eg: Matrix multiplication
2. Partitioning input data
   1. This can be done only if each output can be naturally computed as a function of the input
   2. Eg: Minimum of numbers
3. Partitioning both input and output data
   1. 
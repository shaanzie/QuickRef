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
4. Partitioning intermediate data
   1. Decomposition at an intermediate stage

A decomposition based on partitioning output or input data is also widely referred to as the owner-computes rule. The idea behind the rule is that each partition performs all the computations involving data it owns.

### Exploratory Decomposition

This is used to decompose problems whose underlying computations correspond to a search of space for solutions. The search space is partitioned into smaller parts, and each part is searched concurrently.

### Speculative Decomposition

This is used when a program may take one of the computationally significant branches depending on the output of the other computations that precede it. In this, other tasks that may not take the branch can start executing instructions before the branch is actually evaluated.

### Hybrid Decomposition

The 4 decomposition strategies can also be used in combinations, where different types of decompositions can be applied at different stages.

## Characteristics of Tasks and Interactions

The next step after decomposition is to design an algorithm to map these tasks to available processes.

### Task Characteristics

1. Task generation
   1. Tasks can be generated statically or dynamically
   2. Static is where all the tasks are known before execution, and dynamic is during execution
2. Task Size
   1. Size of a task is the relative amount of time required to complete it.
   2. Tasks can be uniform (same time) or non-uniform.
3. Knowledge of task sizes
   1. If all the sizes are known, parallelism can be efficient
4. Size of data associated with tasks
   1. Data associated with the task must be available to the task.

### Characteristics of Inter-Task Interactions

1. Static or Dynamic
   1. An interaction pattern is static if the interactions happen at predetermined times and if these times are known. It is dynamic if that happens at runtime.
   2. Static interactions can be programmed easily in MP, but dynamic is harder. This is because MP requires involvement of both tasks, and dynamic is too unpredictable.
2. Regular or Irregular
   1. Regular if interaction has structure, irregular otherwise.
3. Read-only or Read-write
   1. In read-only, tasks require only a read-access to the data shared. RW requires both privileges enabled,
4. One-way or Two-way
   1. Work needed by a task is explicitly supplied by other tasks in two way. In one way, only one task does all the interaction work.
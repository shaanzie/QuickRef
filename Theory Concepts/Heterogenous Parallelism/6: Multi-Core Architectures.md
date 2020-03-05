# Multi-Core Architectures

We use multicore because
1. Difficult to make single core clock frequencies even higher
2. Deeply pipelined circuits
   1. Heat problems
   2. Speed problems
   3. Complex design


Simultaneous multithreading (SMT) permits multiple independent threads to execute simultaenously on the same core. Here, a unit not under use when a thread is executing can be used by another thread.

In this, the PC is replicated and a Floating-Point processing unit is introduced. The replication allows multithreading. But this is not scalable, as we cannot just keep adding duplicate elements to the processor.

Introducing SMT may decrease CPI but increase CT. The CT increases due to the increasing register size. 

SMT is not truly parallel, as it cannot handle multiple instructions of the same kind, but gives a notion of parallelism on independent different instructions.

Multicore processors give better parallelism, but require more hardware. Each core is not that sophisticated, and is smaller.

In SMT, all caches are shared. In multi-core, each core may have private caches and shared caches. The memory is always shared.

Advantages of private caches
1. Closer to core, faster access
2. Reduces contention

Advantages of shared caches
1. Threads on different cores can share the same cache data
2. More cache space available

Private caches cause a cache coherence issue. This can be mitigated by using
1. Invalidation with snooping
   1. When a change is made to a cache variable in one core, all copies of that variable in other cores are invalidated
   2. Does not cause traffic on the bus for writes
2. Update
   1. When a change is made, a forceful write is carried out on all cores
   2. Causes a lot of traffic on the bus

Thread safety is very important in SMT
1. Preemptive context switches can happen any time
2. True concurrency is achieved, making bugs exposed much faster with multi-core
3. Synchronization is always required

To assign threads to cores, each thread has an affinity mask specifying what cores the thread is allowed to run on. The default mask is all 1s. The OS scheduler decides what threads to run on what core. It detects skewed workloads, migrating threads to less busy processors.

Soft affinity is a technique used by the scheduler to keep a thread on the same core to reduce migration. Hard affinities are programmer prescribed affinities. This is done when two or more threads share data structures in memory. 

The sched_getaffinity() function retrives the current affinity mask of the process.
The sched_setaffinity() function sets the current affinity mask of the process to *mask.



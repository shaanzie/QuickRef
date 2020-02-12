# Parallel Programming Platforms

## Implicit Parallelism

Clock speed improvements are severely diluted by memory access speed times. But this has been alleviated by a smattering of technologies.

### Pipelining and Superscalar Execution

Pipelining enables faster execution by overlapping execution stages. However, factors such as branch misprediction tend to stagger the performance of the machines. 

In such a case, multiple pipelines are used, where multiple instructions are piped into the processor in parallel. This is superscalar execution.

This has a number of issues
1. True data dependency
   1. Resolution done at runtime, hence, hardware support is needed
   2. Amount of ILP is limited
2. Resource dependency
3. Branch dependency
4. Processor needs to be able to issue out-of-order instructions (dynamic)

The performance of superscalar execution is limited by the availibility of ILP. If during a particular cycle, no instructions are issued on the execution units, it is termed as vertical waste, and if only part of the execution units are used, it is called horizontal waste.

### Very long Instruction Word Processors

The parallelism offered by superscalar instructions is often limited by instruction lookahead. The hardware complexity increases with the number of instructions issued, quadratically.

VLIW is an alternative where compilers are used to resolve dependencies and resource availibility at compile time. Instructions that can be executed concurrently are arranged in groups and parceled off to the processor as a single instruction word to be executed by multiple functional units at the same time.

Some features of VLIW
1. Decoding and issue complexities are simple
2. Compiler has larger context to select instructions and increase parallelism
3. No dynamic programming state available to compilers to make scheduling decisions
4. Reduces branch and memory prediction, but better static prediction
5. Runtime situations are difficult to predict
6. Performance sensitive to the compiler's ability to detect dependency.

## Limitations of Memory System Performance

The rate at which data can be pumped from memory into the processor determines the bandwidth of the memory system. The time taken to retrieve a block of data is known as the latency.

Effective memory latency is improved using caches, where the cache hit ratio determines the performance of the overall system. The effecitve computation rate depends on the bandwidth, and this is referred to as a memory bound.

This is improved by the cache's notion of temporal locality, where the cache stores data used frequently and more recently.

Memory bandwidth refers to the rate at which data can be moved between the processor and memory. This is determined by the bandwidth of the memory bus as well as the memory units.

Wide buses to provide better memory bandwidth are expensive, but allows peak computation rates, as it exploits spatial locality.

Latency hiding can be done through a couple of ideas
1. Multithreading
   1. Processor serves multiple outstanding requests, concurrently
   2. Multithreaded processors can maintain context of a number of threads, hiding concurrency
2. Prefetching
   1. Advance load operations before requested
   
The bandwidth, however, of a multithreaded system can increase significantly because of the smaller cache residency of each thread. At this point, multithreaded systems become bandwidth bound and not latency bound.

Another issue is to deal with hardware resources to be effectively used, such in the case of double fetches.

## The Dichotomy of Parallel Computing Platforms

The dichotomy deals with the logical and physical organization of parallel platforms. 

### Control Structure of Parallel Platforms

Processing units in parallel computers either operate under a centralised control unit, called SIMD, where data is executed synchronously by all execution units, or under different programs independent of processing elements, called MIMD.

SIMD works well for structured computations, such as array computations, but some data items cannot use this model. For this, an activity mask is associated with each data item and the operation that specifies whether it should participate in an operation or not.

In MIMD, with a special focus on Single Program Multiple Data, multiple instances of the same program execute on different data. 

SIMD requires lesser hardware and lesser memory, but MIMD platforms are more robust, and easy to use.

SIMD requires intensive design efforts and longer dev times, causing fast obsolesence.

### Communication Model of Parallel Platforms

1. Shared Address Space
   1. Common data space accessible to all processors
   2. Processors interact by modifying data in this shared space
   3. SPMD + this are referred to as multiprocessors
   4. Memory can be global or local to a processor
   5. Can be uniform (UMA) or non-uniform (NUMA)
   6. Presence of caches raises issues of multiple copies of a shared word being manipulated by two processes (Cache coherence)
   7. Supporting coherence requires a large amount of hardware support
   8. No automatic update or invalidation done
2. Message Passing
   1. Logical view : P processing nodes, each has its own address space
   2. Process interaction done through messages.
   3. Send and Receive operations with target addresses
   4. Costly to emulate shared address space on message passing computers
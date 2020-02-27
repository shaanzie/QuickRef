# Memory Consistency

Memory coherence defines requirements for the observed behavior of reads and writes to the <u>same</u> memory location (ensures all processors have a consistent view of the same address). 
- All processors agree on the order of reads/writes to X
- It is possible to put operations on a timeline and observations of all processors are consistent with that timeline.

Memory consistency defines the behavior of reads and writes to <u>different</u> locations (as observed by other processors).
- Guarantees that writes to address X <u>will</u> eventually propogate to other processors
- Consistency deals with WHEN writes propogate to other processors, relative to reads and writes to other addresses

## Memory operation ordering

A program defines a sequence of loads and stores, called the program order. There are 4 types
1. W -> R
2. R -> R
3. R -> W
4. W -> W

Where A -> B denotes that A must complete before subsequent B.
A <b>sequentially consistent memory system<b> maintains all 4 operation orderings.

A parallel system is sequentially consistent if the result of any parallel execution is the same as if all the memory operations were executed in some sequential order, and the memory operations of any processor are executed in program order. A relaxed memory consistency models allow certain orderings to be violated.
The relaxed model works because the same location is not referred to in memory consistency. Memory coherence takes care of that. 

However, relaxation may not be useful always
1. Dependencies
2. Synchronization mechanisms, when they're not defined properly, reordering can alter program logic

The motivation for relaxed consistency stems from
1. To gain performance
2. Hiding memory latency

To allow the processor to hide latency of writes
- Total Store Ordering (TSO)
  - Processor P can read B before its write to A is seen by all processors
  - Reads by other processors cannot return new value of A until tje write to A is observed by all processors.
- Processor Consistency (PC)
  - Any processor can read the new value of A before the write is observed by all processors

This only relaxes W -> R order. 

## Write Buffering

Write buffering allows processor optimization that allows reads to proceed in front of prior writes.
- When store is issued, processor buffers store in write buffers
- Processor immediately begins executing subsequent loads, provided they do not refer to the same location.
- When read occurs on the same location, it can read from the same buffer
- Cache coherence can happen anytime
- This relaxes the W->R ordering

## Partial Store Ordering (PSO)

Execution may not match sequential consistency in this case, where flag may get updated before A.
```
Thread 1 (on P1)        Thread 2 (on P2)

A = 1                   while(flag == 0) ;
flag = 1                print A;
```

## Allowing all reorderings

Examples
1. Weak ordering
2. Release consistency
   1. Processor supports special synchronization
   2. Memory accesses before memory fence instruction must complete before fence issues
   3. Memory access after fence cannot begin until fence instruction is completed

## Expressing synchronization in relaxed models

Fence is like a sync instruction. Till the fence, all memory operations must complete. None shall pass until all the memory operations are completed.

- Intel x86 ~ TSO
  - Provides sync instructions if software requires a specific instruction ordering not guaranteed by the consistency model
    - mm_lfence() = load fence : wait for all loads to complete
    - mm_sfence() = store fence : wait for all stores to complete
    - mm_mfence() = mem fence : wait for all mem operations to complete

- ARM processors ~ Very relaxed model


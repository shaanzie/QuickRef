# Introduction to Parallel Computing

Moore's argument for parallel systems was that the complexity of the minimum component costs increases by a factor of 2 each year. This was based on a log linear relationship between device complexity and time. He defined two factors for this complexity increase - bigger dies and finer dimensions.

Formally, Moore's law states that the circuit complexity doubles every 18 months. 

The overall speed of computation is determined by
1. Speed of processor
2. Ability of memory system to feed data to it.

Since DRAM access time has increased, with increases in IPC, the gap between processor speed and memory defines the key bottleneck. This is typically bridged by caches, and the performance depends on the number of cache hits.

Parallel platforms give better performance as
1. Larger aggregated caches
2. Higher aggregated bandwidth to the memory
3. Provide support for out-of-core computation

The main motivation for parallel computing arises from data locations, and the infeasibility of high compute where data transfer takes too long.

## The Scope of Parallel Computing

Parallel Computing applies to various fields
1. Engineering and Design
2. STEM research
3. Commercial applications
4. Computer System Architecture
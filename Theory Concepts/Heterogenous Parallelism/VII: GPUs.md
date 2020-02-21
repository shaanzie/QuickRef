# Graphic Processing Units

The graphics pipeline converts a 3D vector object into a rendered 2D screen, atleast in the earlier GPUs.

Vector images specify 3D objects as a set of vector coordinates. These vector coordinates are projected into a 2D specification. Rastrization is converting vector graphics to pixel graphics. OpenGL was used to compute this pipeline, which renders 3D images into 2D.

1. A thread is the smallest grain of the hierarchy of device computaton.
2. A block is a group of threads
3. A grid is a group of blocks
4. A warp is a group of 32 threads executed simultaneously on the device
5. The kernel is the creator of a grid for GPU execution.

The computational elements of a GPU are
1. Streaming processor - core of the design, computation space, massive SIMD engine
2. Streaming multiprocessor - groups of streaming multiprocessors, contain special function units and load/store units
3. Instructional Schedulers
4. Complex control logic

The different types of GPU memory are
1. Global
   1. DRAM
   2. Slowest
2. Texture
   1. Cached global memory
   2. Bound at runtime
3. Constant
   1. Cached global memory
   2. Read only memory
4. Shared
   1. Local to a block of threads

This is all seen in a Fermi architecture. The improvements that Fermi made are
1. Increased the number of SPs per SM
2. Unified request path for load/store instructions
3. Implementation of cache hierarchy
4. Register spilling
   1. Uses cache instead of RAM

In the Kepler SM architecture
1. Improves GPU performance and power efficiency
2. Increased to 192 SPs per SM
3. 32 special FPUs
4. Improved Warp performance

There exist 4 warp schedulers, where each scheduler can issue upto 2 independent instructions when it is ready to issue.

The Kepler Memory is
1. Shared memory and L1 are still physically shared
2. New read only cache
3. Increased L2 cache.

In Fermi, the data could only be exchanged between threads using shared memory, which led to additional synchronization time.

Kepler allows shuffle functions which allows exchange data between threads without shared memory, handling load/store in a single step. Data can only be shared within the single warp.

The Kepler hardware offered a lot of features
1. Dynamic parallelism
   1. Any kernel can launch more kernels
   2. Takes additional load off CPU
2. HyperQ
   1. 32 hardware managed work queues
3. Grid Management Unit
4. NVIDIA GPUDirect
   1. Ability for CUDA enabled GPUs to interact without the need for CPU intervention
   2. GPU can interact directly with NIC

## CUDA

CUDA stands for a compute unified device architecture, and is used widely in modern GPUs. it allows a programming paradigm where each computation takes place on a separate thread.
Explicit Memory operations are used to allocate and copy data from CPU to GPU. All kernels execute asynchronously, with explicit barriers between processors.

To meet data dependencies, synchronization primitives are used
1. _syncthreads() - sync threads in a block
2. Atomic operations

Performance is dictated by memory operations and synchronization cost
1. Memory coalescence
2. Warp divergence

## HSA

HSA unites accelerators architecturally, by making them
1. Easier to program
2. Easier to optimize
3. Higher performance
4. Lower power

HSA allows features of
1. Unified addressing
2. Operation into pageable system memory
3. Full memory coherency
4. User mode dispatch
5. Architected queuing language
6. High language support for GPU compute processors
7. Preemption and context switching

HSAIL is the HSA intermediate layer, which is a virtual ISA for parallel programs. It is explicitly parallel, gives support to other high level language features, and high level frameworks.

The HSA memory model defines visibility ordering between all threads. It provides a relaxed consistency memory model for parallel compute. Its visibilities are controlled by 
1. Load.Acquire
2. Store.Release
3. Barriers

The HSA Queuing Model is defined as
1. User mode queuing for low latency
2. Architected queuing layer
3. Allows for dipatch to queue from any agent
4. GPU self enqueue enables lots of solutions

The HSA has its own JIT compiler that runs in the runtime environment. It runs on top of frameworks as a platform architecture.

Bolt is a parallel primitives library for HSA, which
1. Easily leverages the inherent power efficiency of GPU computing
2. Heterogeneous compute
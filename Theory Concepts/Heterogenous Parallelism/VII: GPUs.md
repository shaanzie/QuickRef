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

This is all seen in a Fermi architecture.

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


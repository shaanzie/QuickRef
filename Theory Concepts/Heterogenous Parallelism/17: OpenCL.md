# OpenCL

- Programming Framework for CPUs, GPUs, DSPs, FPGAs with a programming language
- It provides a programming framework for portable, parallel programming of devices in heterogeneous environments
- CUDA
  - Mature and efficient
  - Many tools and extra libraries
  - Only usable by NVidia GPUs
- OpenCL
  - For various processor types
  - Supports heterogeneous platforms
  - Not as mature and widely used
  - Partly long winded programming

- Architecture
  - Conceptional Level
    - Platform model
    - Execution model
    - Memory model
    - Programming model
  - Programming level
    - OpenCL Platform API
    - OpenCL Runtime API
    - OpenCL C
  
- Platform Model    
  - Host provisions tasks on compute devices
  - Processing elements make compute units, which inturn make compute devices
  - Every OpenCL implementation with library defines a platform
  - One host can have multiple platforms (installable client driver model) 
  - Mechanism at runtime
    - libOpenCL.so is dynamically linked to your application at runtime
    - ICD loader uses dlopen() to open all platform specific OpenCL libraries
    - Calls to OpenCL library functions routed to correct implementation
- Execution model
  - Work groups defined, with work items in each group.
  - NDRange specifies the index offset for a work-item
  - Excursus - Thread Management on GPUs
    - Kernels:  Function for execution on device
    - Thread management is done in a heirarchical organization
      - Upper level : Grid - NDRange
      - Medium level : Block - Work group
      - Lower level : Thread - Work item
    - Scheduler can be
      - Block - Coarse Grained
        - Distributes groups of work-items to SMs
        - Takes free capacity into account
        - Load balancing
      - Warp/Wavefront - Fine grained
        - Wavefront in AMD is a group of 64 work items which are scheduled together
        - SIMD level
  - The Host defines a context as
    - Devices
    - Kernels
    - Program Objects
    - Memory Objects
  - The host manages queues
    - Kernel Execution
    - Operations on memory objects
    - Synchronization
- Memory Model
  - Host has a host memory and has a link to a global and constant memory in the context
  - The context contains work groups with their own local memories, and work items with private memory
  - Follows a weak consistency model
- Programming Model
  - Data Parallel
    - Possible mappings with data and NDRange
      - 1:1 mapping
      - More flexible mappings possible
    - Favours GPUs
  - Task Parallel
    - Execution of only a single kernel instance
    - Parallelism via
      - SIMD units on device
      - Multiple tasks in queue executed async
    - Can work on multicores better
- OpenCL programming steps

1. Determine components of heterogeneous systems
2. Query specific properties of each component to adapt execution dynamically during runtime
3. Compile and configure the OpenCL kernels
4. Create and initialise memory objects
5. Execution of the kernels in correct order with the best suited device for each kernel
6. Collection of results

- Basic Programming Steps in API

1. Query platforms - selection
2. Query devices of the platform - selection
3. Create context for devices
4. Create queues for context and device
5. Create program objects
6. Create memoyr objects
7. Kernel execution
   1. Kernel arguments
   2. Put kernel into queue
8. Collect results
9. Free OpenCL resources


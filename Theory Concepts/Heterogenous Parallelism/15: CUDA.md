# CUDA

- CUDA programming model allows to program the GPU and the CPU with one construct
- CUDA calls the CPU the host and the GPU is the device
- CUDA assumes the device is a coprocessor to the host with seperate memory
- Each have their own dedicated memory
- The CPU sends directions to the GPU
  - Moving data between memory - memcopy
  - In CUDA, the command is cudaMemcpy
  - Allocation : cudaMalloc
  - Launching a kernel : Host launches kernels on the device

- A typical GPU program looks like
  - CPU allocates storage on GPU
  - CPU copies input data to GPU
  - CPU launches kernels on the GPU to process the data
  - CPU copies results back to CPU from CPU
- We need to have a high level of computation to communication
- The Computation is structured as one or more kernels
- Kernels look like serial programs, and we write your program as it runs on a single thread, and then tell the GPU <b>how many threads to run this on</b>.
- The GPU is good at
  - Efficiently launching a number of threads
  - Running a lot of threads in parallel
- The cudaLaunch operator is given by <<<>>> and launches the kernel depending on the size
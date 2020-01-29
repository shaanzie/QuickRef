# Analytical Modeling of Parallel Systems

To say a program is better than a serially executed program, we use certain performance metrics to benchmark applications.

A sequential algorithm is generally evaluated by its runtime, as a function of the input size, and the asymptotic runtime of a sequential program is identical on any serial platform.

The parallel runtime of a program depends on the input size, the number of processors and the communication parameters of the machine.

We do not consider the architecture upon which the program is running.

Total time to run a parallel program is given by N x T<sub>p</sub>, where N is the number of processors and T<sub>p</sub> is the time taken to run the code on a single parallel processor.

## Sources of Overhead

The overheads that occur in parallel programs are
1. Interprocess interactions
2. Idling
3. Excess computation

Parallel programs are also affected by the output size, as transferring this output accross processors acquires large overhead.

## Performance metrics for Parallel Systems

We use execution time as a performance metric to compare parallel and serial processes, which is the time of start of execution till time of completion.

Total parallel overhead is another metric used.

Speedup is also used, where it is the ratio of the serial time to parallel time.

Efficiency is used, where it is given by the speedup / number of processes, and it is a measure of the fraction of time which a processing element is usefully employed.

The cost of a parallel system is used widely, and it is given by the product of the parallel runtime and the number of processing elements use (p x T<sub>p</sub>). It reflects the sum of the time that each processing element spends solving the problem.

A parallel system is said to be cost optimal if the cost of solving a problem on a parallel system is asymptotically better than a serial program.

To improve cost optimality, we add granularity on the performance. A slow down is done, where number of processors is reduced to provide more data elements to these processors.
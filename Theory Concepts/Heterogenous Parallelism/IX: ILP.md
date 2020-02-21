# Instruction Level Parallelism

Instruction level parallelism is parallelising or executing multiple instructions in parallel. The pipeline CPI is given by
```
Pipeline CPI = Ideal Pipeline CPI + Structural stalls + Data hazard stalls + control hazard stalls
```
Overlapping instructions may not be independent in pipelining. Here, the ideal pipeline CPI is a measure of the maximum performance attainable by the implementation. The structural hazard stalls are the limits on hardware. Data hazards happen when instructions depend on the outputs of other instructions in the pipeline. Control hazards are usually caused by the delay between fetching instructions and decisions about changes in control flow.

To mitigate structural hazards, we cannot just keep increasing the number of structural elements, due to 
1. Cost
2. Power
3. CTs cubic dependency on number of ports

Data dependence hazards or true dependencies can be of 3 types
1. Read-After-Write
2. Write-After-Read
3. Write-After-Write

An antidependence occurs when a location is in execution and subsequent instructions store results in this location. This is a name dependency, and is done by a programmer to remove structural hazards. 

In control dependencies, hoisting can be done when statements resulting from a control statement execute before the condition. This may be avoided because if the instructions have exceptions or interrupts, they may lead to program crashes, even if the condition evaluates to false. Exceptions need to be precise to handle these types of errors.

In looping constructs, we use load cascading to load multiple registers and do multiple updates without stalls, such as unrolling. If this unroll limit exceeds a certain point, however, the law of diminishing performance takes over.

## Limits on ILP

The ideal machine is defined by
1. Register renaming - infinite registers
2. Perfect branch prediction
3. All addresses known exactly
4. Perfect caches
5. Infinite resources
6. All FUs have unit latencies
7. Processors can issue unlimited instructions by looking into the future of computation

In experiments, this is done by a MIPS optimizing compiler, with program traces available before hand. Now we start limiting parameters for the effects.

### Window size

When window size is limited to n, it affects
1. Instruction storage
2. Maximum issue rate
3. Number of operand comparison for dependence checking

Instruction issues per cycle decrease as window size decreases. Here,
1. Integer programs do not have as much parallelism as FP programs
2. Highly dependent on loop-level parallelism

### Branch Prediction

Considering 5 alternatives
1. Perfect
2. Tournament predictor
3. Standard 2 bit predictor
4. Static
5. None

The prediction scheme varies from workload to workload. 

### Finite Registers

As registers decrease,
1. Not a big difference in integer programs, as they are already limited by branch prediction and window size.

### Imperfect Alias Analysis

Memory can have dependencies too. In this we consider 3 models
1. Global/stack perfect
2. Inspection : Inspecting base registers and constant offsets
3. None : All references are assumed to conflict

Inspection and None have significantly low scores. Dynamic memory disambiguation is constrained by
1. Each load address should be compared with all stores
2. The number of references analysedper cycle
3. Amount of load store buffering can predict how far the load store can be moved
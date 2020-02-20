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
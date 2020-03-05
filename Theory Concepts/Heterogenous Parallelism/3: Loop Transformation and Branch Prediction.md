# Loop Transformation and Branch Prediction

The principle of locality is the tendency of accessing the same set of locations repetitively over a short period of time.

## Loop Unrolling Decisions

1. Determine loop unrolling useful by finding that loop iterations were independent
2. Use different registers to avoid uncessary constraints
3. Eliminate extra test and branch instructions and adjust the loop termination and iteration code
4. Determine that loads and stores can be interchanged by observing that loads and stores are independent for different iterations, if they don't point to the same memory location
5. Schedule the code, preserving dependencies

Limits of loop unrolling are
1. Decrease in amount of overhead is amortized by Amdahl's law
2. Growth in code size, increasing instruction cache miss rate
3. Register pressure : Potential shortfall in registers created by aggressive unrolling and scheduling
4. Reduces impact of branches

## Dynamic Branch prediction

Dynamic branch prediction is almost always better than static branch prediction. Its performance is given by f(accuracy, cost of misprediction).

A branch history table is maintained, where the lower bits of the PC address the index table of 1 bit values. It says whether or not branch was taken last time, with no address check. However in loops, this always guarantees two misses, one at entry and one at exit.
For this, we add a 2 bit scheme which says that if the misprediction occurs twice, we change the prediction, else, we stick.

## Correlated Branch Prediction

The idea is to record m most recently executed branches as taken or not taken, and use that pattern to select the proper n-bit branch history table. In general, the (m,n) predictor means record last m branches to select between 2<sup>m</sup> history tables, each with n bit counters. This makes the old BHT a (0, 2) predictor.

The global branch history is an m-bit shift register keeping T/NT status of the last m branches.

## Tournament Predictors

These are multilevel branch predictors, using an n bit saturating counter to choose between predictors. The usual choice is between global and local predictors. The advantage of doing this is the ability to select the right predictor for a particular branch, which is crucial for benchmarks.

## Branch Target Buffers

Branch target calculation is costly and stalls the instruction fetch. BTB stores PCs the same way as caches. The PC is sent to the BTB, and if the match is found, the predicted PC is sent. If the branch was predicted taken, instructions execute from the predicted PC.

## Advantages of Dynamic Scheduling

The main idea of dynamic scheduling is to avoid instructions that have no dependencies on previous instructions to have stalls.

1. Hardware rearranges instruction execution to reduce stalls while maintaining code integrity and exception handling
2. Handles cases where dependencies are unknown at runtime and allows toleration of unpredictable delays
3. It allows code that compiled for one pipeline to be run efficiently on another
4. Simplifies the compiler
5. Speculation gives several advantages

## Steps in Dynamic Scheduling - Tomasulo's Algorithm

1. Split the ID pipeline stage into 2
   1. Issue : Decode instructions, check for structural hazards
   2. Read operands : Wait until no data hazards, then read operands

This algorithm was designed before caches. The goal was to achieve high performance without special compilers. This works on the basic principle of renaming registers, due to the small number of registers available at the time of development.

We buffer data dependent instructions in Reservation Stations. When the data is available for this instruction, the results are broadcasted onto the common data bus, so that the RS can send the instruction for execution. This issues inorders, but causes out of order execution. This does not support precise exception handling.

Tomasulu's pipeline phases are
1. IF : Fetch 
2. Issue phase
   1. If matching RS is free, issue instr to RS
      1. With operand values, if registers are available
      2. Otherwise, with identifiers that will produce the operands
   2. Else, structural hazard
3. Execute
   1. When there is no RAW and FU free
   2. If not, monitor CDB for result
4. Memory
5. WB

Each RS has 7 fields
1. op : operation to perform
2. RS1 : RS that will produce 1st operand value (0 : operand available)
3. RS2 : RS that will produce 2nd operand
4. Val1 : Value of 1st operand
5. Val2 : Value of 2nd operand
6. Imm/addr : Holds immediate or effective address
7. Busy : RS occupied

It offers two main advantages
1. Distribution of the hazard detection logic
2. Elimination of stalls for WAW and WAR hazards

Its drawbacks are
1. Complexity
2. Many associatve stores (CDB) at high speed
3. Performance limited by CDB
4. Non-precise interrupts


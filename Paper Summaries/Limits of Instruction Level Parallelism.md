# Limits of Instruction Level Parallelism

## Abstract

By performing simulations based on instruction traces, techniques can be modeled at the limits of feasibility and even beyond. The study shows a striking difference between assuming that the techniques we use are perfect and merely assuming that they are impossibly good.

## Introduction

In naive cases, the parallelism of a given piece of code is the number of instructions divided by the number of cycles required. Architectures to take advantage of this kind of parallelism have been proposed. The superscalar machine is one that can issue multiple independent instructions in the same cycle. A superpipelined machine issues one instruction per cycle, but the cycle time is much less than the typical instruction latency. A VLIW machine is like a superscalar machine, except that the parallel instructions must be explicitly packed by the compiler into long instruction words.

Parallelism in a basic block rarely exceeds 3 or 4 on average. Peak parallelism may be higher, but the payoff for high peak parallelism is low if the average is still small. These limits are troublesome, as many machines already have some degree of pipelining. This degree is calculated by multiplying the latency of each operation by its dynamic frequency in typical programs. Adding a superscalar capability to a machine with some pipelining is beneficial only if there is more parallelism available than the pipelining already exploits.

To increase ILP, there are two broad categories. One includes techniques for increasing parallelism in the basic block, and others for using parallelism across several basic blocks. The effectiveness of a technique is bound by whether it is used in combination with impossibly good companion techniques, or with none. The paper describes the use of trace-driven simulation to study the importance of register renaming, branch and jump prediction, and alias analysis.

## Increasing Parallelism within blocks

Parallelism within a basic block is limited by dependencies between pairs of instructions. Some of these are true dependencies, and some of these are false.
```
r1 := 0[r9]
r2 := r1 + 1
r1 := 9
```
Old compilers often do not pay attention to the allocation of registers, preferring to reuse registers as often as possible. An alternative to this is using <b>register renaming</b>, where the hardware imposes a level of indirection between the register number appearing and the register actually used. This allocation is done dynamically, and allows more registers to be fit than the instruction format, reducing false dependencies. However, this can also lengthen the machine pipelining, introducing branch penalties, but the concern is just parallelism.

False dependencies may also involve memory. Hardware renaming memory locations is undesirable, but we can make conservative assumptions that may lead to false dependencies in memory. For example
```
r1 := 0[r9]
4[r16] := r3
```
There is no way of knowing whether the locations referred to are the same. 

<b>Alias analysis</b> helps a compiler decide whether two memory references are independent, but that might be imprecise as well. This can be resolved at runtime by determining the actual address referenced, but may be too late for parallelism. We must always assume the worst.

## Crossing Block Boundaries

Branch prediction is a common hardware technique, where it maintains a table of two-bit entries, where the lower order bits of a branch address provide the index into the table. Taking a branch causes us to increment this table entry, not taking it causes a decrement. A branch is taken if its table entry is 2 or 3. This mispredicts a typical loop only once, when it is exited. 

This is often used to keep a pipeline full, where we fetch and decode while the logic figures out whether to take the branch or not. To use branch prediction to increase parallelism, we need to execute instructions across an unknown branch <b>speculatively</b>. This may involve maintaining shadow registers, whose values are not commited until the branch is correctly predicted. Squashable instructions need to be maintained to avoid any uncessary load stores. The architecture may have limits on the amount of fanout it can tolerate. 

The destination of branch and jump instructions can be known well in advance. The destination of a indirect jump may take some time. The jump prediction scheme outlined is that a table is maintained for destination addresses. The address of a jump provides an index into this table. Whenever an indrect jump is executed, the table gets a new entry. 

Loop unrolling removes a great percentage of branches. Software pipelining is a compiler technique of moving instructions across branches to increase parallelism. It analyses dependencies and increases parallelism by moving instructions. Trace scheduling was developed for VLIW, where global scheduling by the compiler is needed to exploit the parallelism of the long instruction words. It uses a profile to find the trace of blocks execute often, and schedules them as a whole. This predicts a branch statically, based on the profile. 
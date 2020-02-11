# Multi-Core Architectures

Simultaneous multithreading (SMT) permits multiple independent threads to execute simultaenously on the same core. Here, a unit not under use when a thread is executing can be used by another thread.

In this, the PC is replicated and a Floating-Point processing unit is introduced. The replication allows multithreading. But this is not scalable, as we cannot just keep adding duplicate elements to the processor.

Introducing SMT may decrease CPI but increase CT. The CT increases due to the increasing register size. 

SMT is not truly parallel, as it cannot handle multiple instructions of the same kind, but gives a notion of parallelism on independent different instructions.

Multicore processors give better parallelism, but require more hardware. Each core is not that sophisticated, and is smaller.
# PGAS 

- A parallel program consists of a set of threads and at least one address space
- A program has a global view if all threads share a single address space (OpenMP)
  - Can cause race conditions and communication overhead
- A program has a local view if the threads have distinct address spaces and pass messages to communicate (MPI)
  - Lot of bookkeeping, and replicated data


- The Partitioned Global View or PGAS has
  - Global address space : Every thread sees entire dataset
  - Partitioned: Divide global address space so programmer is aware of data sharing

- In X10, memory is called a place
- Contains structures of data
- Partitioning occurs which divides the structure into parts
- Mapping occurs on partitions

- Threads are created dynamically during execution with `async` and `at`.
- Affinity is the association of a thread to a memory
  - If thread has affinity, it has access to those structures

- Collective operations are performed by a set of threads to accomplish a single global activity
- The Owner computes rule 
  - Distributes map data to (or accross) memories
  - Affinity binds each thread to a memory


## X10

- X10 is an instance of the async PGAS model in the JAVA family
- PGAS memories are called places in X10
- PGAS threads are called activities in X10
- X10 goals
  - Simple
  - Safe
  - Powerful
  - Scalable with concurrent tasks
  - Universal core programming model
- Focus on HPC style numeric computing

Hello World

```
public class Hello {
    public static def main( var args: Array[String](1)):Void {
        Console.OUT.println("Hello X10 world!");
    }
}
```

- val declares an immutable value with type inference
- Declare everything as val unless var is explicitly required


- Parallelism comes from Activities and Places
- Basic constructs: async, at, finish, atomic
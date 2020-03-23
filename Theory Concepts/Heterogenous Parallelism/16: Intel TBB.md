# Intel TBB

- Style of quick parallelisation in C++
- Converts serial code into parallel code
- It composes different parallelism constructs

- Provides library parallelism
  - Nested parallelism
  - Conversion of serial to parallel code

- It provides
  - Parallel algorithms and data structures
  - Threads and synchronization primitives
  - Scalable memory allocation and task scheduling

- It contains 3 levels of parallelism
  - Task Parallelism / Message Passing
  - Fork-Join parallelism
  - SIMD parallelism

- Express programs in terms of flow graphs
- It provides generic parallel algorithms which are scalable
- The flow graph is a set of classes to express parallelism as a graph of compute dependencies
- It also has a task scheduler which is workstealing, and the threads = number of cores

## Flow Graph

- Efficient implementation of dependency graph and data flow algorithms
- Designed for shared memory applications
- Enables devs to exploit parallelism at higher levels
- Can specify graph objects

A Hello world program:
```
graph g;
continue_node<continue_msg> h(g, [] (const continue_msg &) {
    cout<<"Hello";
});
continue_node<continue_msg> w(g, [] (const continue_msg &) {
    cout<<"World\n";
});
make_edge(h, w);    // Dependency
h.try_put(continue_msg());  // Call the function
g.wait_for_all();   // Wait for every thread to return
```

- The Intel TBB Flow Graph allows the following node types
  - Functional
  - Buffering
  - Split/Join
  - Other

## Heterogeneous Support in TBB

- 
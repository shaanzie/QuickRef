# Concurrency in C++11

C++11 offers shared memory parallelisation
- Threads
- Race conditions
- Mutexes
- Atomicity
- Asynchronous Tasks
- Condition variables

New threads are created by
```
#include<iostream.h>
#include<thread>

void func(int x) {
    cout<<"Inside thread"<<x<<endl;

}

int main() {
    thread th(&func, 100);
    th.join();
    cout<<"Outside thread"<<endl;
    return 0;
}
```

- This_thread refers to the thread currently executing.
- 
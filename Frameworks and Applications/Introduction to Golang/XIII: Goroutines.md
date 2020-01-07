# Goroutines

Go uses goroutines to introduce concurrency in Go programs. This is done by using the keyword `go` which allows the creation of 'green threads' for certain routines.
A goroutine is an abstraction of threads. The scheduler at runtime maps these goroutines to OS level threads, allowing user interaction only with high level threads. This allows low stack spaces, allowing easy creation and destruction.

The Go scheduler does not interrupt a thread unless a wait routine is called. This might introduce some non-determinism and race conditions. Arguments are used to couple variables into goroutines to remove this non-determinism.

An alternative is a Wait Group, where Wait Groups allow consistency to synchronize go routines, allowing only one function to execute at a team. But incase of 2 or more goroutines and a wg.Add(2) is used, race conditions can occur again.

Synchronization can be done in another way, using mutex, or mutually excluded locks. Locks and unlocks can be done using RLock and RUnlock. GOMAXPROCS can be used to limit the number of threads at runtime.

The best practices in goroutines to be followed are
1. Don't create goroutines in libraries
   1. Let consumers control concurrency
2. When a goroutine is created, know how it will end
   1. Avoids subtle memory leaks
3. Check for race conditions at compile time
   1. This is done by adding a -race flag to go run.
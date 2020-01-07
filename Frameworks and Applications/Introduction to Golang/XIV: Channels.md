# Channels in Go

Channels are used to synchronize data transmission between different goroutines. Channels are mad using `ch := make(chan int)` where chan is the keyword for the channel and the int denotes the type of data passing through the channel.
This shows that channels are statically typed, and the channel can send and receive messages only of that type.

Receiving and sending from/to the channel is done by `<- ch` and `ch <-` showing the direction of dataflow.

Deadlocks can occur when the number of senders exceed the number of receivers. This can be solved using buffered channels. This is given by a second parameter in the make, where the buffered channel can store the number of variables specified by the second parameter.

The main problem with channels in Go is that the status of whether a channel is open or not is not defined by Go, apart from the application beginning to panic. This has to be handled by something like a defer, or the `ch, ok` syntax on the make command.

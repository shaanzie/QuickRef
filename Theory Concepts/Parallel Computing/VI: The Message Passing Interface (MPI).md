# The Message Passing Interface (MPI)

MPI provides source-code portability of message-passing programs written in C or Fortran across various architectures. It is portable and protects investment.
It was the first effort to produce a MPI standard across the parallel computing industry.

MPI offers
1. Source code portability
2. Efficient implementation across a range of architectures
3. Functionality
4. Support for heterogeneous parallel architectures

MPI does not offer
1. Initial loading of processes into processors
2. Spawning processes during execution
3. Debugging
4. Parallel I/O

The result of mixing MPI with other communication methods is undefined, but MPI is guaranteed not to interfere with the operation of standard language operators such as write, printf, etc. It can be mixed but OpenMP, but it may not be thread-safe, and thread synchronization must be explicitly defined.

MPI maintains internal data structures, referenced through handles.

MPI errors are handled by integer error tokens in C and IERROR arguments in Fortran. A complete set of errors is not defined in MPI, and MPI does not guarantee to catch all errors.

All MPI routines begin with the prefix MPI_ to avoid name collisions. The first MPI routine called is the INIT routine that needs to be called only once. It defines a MPI_COMM_WORLD which is a communicator. All MPI communications need a communicator argument, and MPI processes can communicate only if they share the same communicator.

Every communicator contains a group which is a list of processes. A group is local to a particular process. The group contained within a communicator has been previously agreed across the processes at the time when the communicator was set up.

The processes are ordered and numbered consecutively from 0, the number being the rank. This identifies each process within the communicator.

MPI_FINALIZE is called when all the communications have been completed, and this cleans up all the MPI data structures.

MPI_ABORT attempts to abort all processes in the group contained in the comm so the whole program terminates.

An MPI process can query a communicator for information with MPI_COMM_SIZE and MPI_COMM_RANK. MPI_COMM_SIZE returns the number of processes in the group associated with the communicator, and MPI_COMM_RANK returns the rank of the calling process in the group addociated with the communicator comm.

## The MPI Message

An MPI message is an array of elements of a particular MPI datatype. All MPI messages are typed in the sense that the type must be specified in send and receive. The datatype specified in the receive must match the datatype specified in the send.

The main advantage of MPI is that it can support Heterogeneous parallel architectures, because type conversions can be performed when necessary.

More complex datatypes can be constructed at runtime. These are called derived datatypes and are built from the basic datatypes. They can be used for sending strided vectors, C structs, etc. MPI_BYTE is used to represent 8 binary digits.

## Point to Point Communication

A Point to Point communication always involves exactly two processes. The other type is collective communication, which involves a group of processes in simultaneous communication.

To send a message, a source process makes an MPI call which specifies a destination process in terms of its rank in the appropriate communicator. The destination process also has to make an MPI call to receive the message.

There are 5 communication modes provided, corresponding to 4 different sends.
1. Synchronous send
   1. Only completes when the receive is completed
   2. MPI_SSEND
2. Buffered send
   1. Always completes, irrespective of receive
   2. MPI_BSEND
3. Standard send
   1. Either synchronous or buffered
   2. MPI_SEND
4. Ready send
   1. Always completes, irrespective of receive
   2. MPI_RSEND
5. Receive
   1. Completes when a message is arrived
   2. MPI_RECV

All modes exist in both blocking and non-blocking forms, where in the blocking forms, return from the routine implies completion. In the non-blocking form, all modes are tested for completion with the usual routines.

## Standard Send

The standard send completes once the message has been sent, which may or may not imply that the message has been received. The rules this obeys are
1. It should not assume that the send will complete before the receive begins
2. It should not assume that the send will complete after the receive begins
3. Processes should be eager readers, guaranteed to receive all messages sent, or there will be network overload.

The form is MPI_SEND(buf, count, datatype, dest, tag, comm) where
1. buf is the address of the data to be sent
2. count is the number of elements of the MPI datatype which buf contains
3. datatype is the MPI datatype
4. dest is the destination process for the message, specified by rank
5. tag is a marker used by the sender to differentiate between messages
6. comm is the communicator shared by the sending and receiving processes
7. IERROR contains the return value for the Fortran version

Completion of a send means the send buffer can be safely reused.

## Synchronous Send

If the sending process needs to know that the message has been received by the receiving process, then synchronous communication is used. The routine is similar to standard send as MPI_SSEND(buf, count, datatype, dest, tag, comm).

If a process executing a blocking synchronous send is ahead of the receive, then it will be idle till the receiving process catches up. This is slower than standard mode, but is safer due to no overloads, and leads to better determinism. Debugging is also easier, with unwanted synchronization issues being avoided with non-blocking synchronous communication.

## Buffered Send

Buffered send guarantees to complete immediately, copying the message to a buffer for later transmission. The main advantage over synchronous send is predictability, where the sender and receiver are guaranteed not to be synchronised. The disadvantage is it cannot assume any preallocated buffer space and shoudl explicitly attach enough buffer space for the program. Non blocking buffered send has no advantage over blocking buffered send.

To use the buffered mode, the user must attach buffer space by MPI_BUFFER_ATTACH(buffer, size). It is detached with MPI_BUFFER_DETACH.

Buffered sends and non blocking communication have their own pros and cons
1. Buffered sends require extra buffer space and attached
2. Buffered sends require copying of data into and out of system buffers while non blocking comms does not
3. Non blocking comms require more MPI calls for the same communication

## Ready Send

Ready send is similar to buffered send, where it completes instantly. But, if no matching receive has been posted, the outcome is undefined. The sending process just hopes that the receiving process catches it, or drops it. This avoids the handshaking, and is safe if the control flow of the program allows it.

Ready mode is difficult to debug, and is used where performance is critical as MPI_RSEND(buf, count, datatype, dest, tag, comm).

## The standard blocking receive

The format is MPI_RECV(buf, count, datatype, source, tag, comm, status).

## The Communication Envelope

A communication envelope is used to distinguish between messages. This is returned from MPI_RECV as status. This argument can be queried directly to find out the source or tag of a message that has been received. 

The message received need not fill the receive buffer, The count argument specified to the receive routine is the number of elements for which there is space in the receive buffer, This can be returned by MPI_GET_COUNT(status, datatype, count).

## Rules of Point-to-Point communication

1. Messages do not overtake each other
2. It is not possible for a matching send and receive pair to remain permanently outstanding
3. Same datatypes must participate in send and receive

## Non Blocking Communications

Blocking communications do not return until the communication has completed. This can result in deadlocks. This also leads to very slow communication with dependencies. Latency hiding occurs when a process is idling due to the non-receive of the communication, and the latency is overlapped with useful work.

With non blocking, communication can occur in the background and the process can do other work. This divides the communication into two steps, initiation and completion.
Non blocking routines have an additional argument, request, and they are prefixed as MPI_ISEND and so on, similar to their blocking counterparts.

In non-blocking sends, the sending process initiates the send using MPI_ISSEND and continues with other computations which do not alter the send buffer. Non blocking receives may match blocking sends too, with MPI_IRECV. The receiving process can carry on computations until it needs the received data.

## Testing communications for completions

Completion tests come as
1. WAIT Type : Block until communication has completed
   1. MPI_WAIT(request, status)
2. TEST Type : Boolean depending on whether communication has been completed
   1. MPI_TEST(request, flag, status)

Several non-blocking communications can be posted at the same time. These can be tested by three routines
1. Test for all
   1. MPI_WAITALL and MPI_TESTALL
   2. MPI_WAITALL(count, array_of_requests, array_of_statuses) or MPI_TESTALL with additional flag
   3. Blocks until all the communications specified by the handle are completed
2. Test for any
   1. MPI_WAITANY and MPI_TESTANY
   2. MPI_WAITALL(count, array_of_requests, index, status) or MPI_TESTALL with additional flag
   3. Blocks till one or more communications associated with handle is completed
3. Test for some
   1. MPI_WAITSOME and MPI_TESTSOME
   2. MPI_WAITALL(count, array_of_requests, outcount, array_of_indices, array_of_statuses) or MPI_TESTALL with additional flag
   3. Blocks till some communications are completed


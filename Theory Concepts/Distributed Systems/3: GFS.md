# Google Filesystem

- Storage is a key abstraction used in distributed systems. Key features woud be
  - Performance -> Sharding
  - Fault tolerance -> Replication
  - Consistency

- Strong consistency
  - Each request is executed one at a time (Atomicity)
  - There is still ambuigity if two clients write at the same time to the same key, upon reads
  - Needs more communication

- GFS
  - Big Sequential Access
  - Global FS
  - Sharding
  - Automatic recovery

- Single Master
  - Works fine
  - Contains array of chunk handles
  - Map of handles to chunk metadata
  - Lease expiration times

- Writes
  - Version number written for consistency
  - Updates happen when server crashes based on version number
  - Master writes its own version number to disk to bring back consistency when it crashes
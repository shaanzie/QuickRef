# Lock Freedom

Why don't we want locks?
- Ensure progress
- Lock bugs reduced
  - Busy waiting
  - Livelock
  - Deadlocks
  - Starvation
- Dead threads holding locks may never be freed

A significant part of the computation goes into lock synchronization.
When a small atomic section is there, overheads still might be significant, due to these activities having the probability of being in a loop. 

Instead, we try a lock-free synchronization
- Assumes its alone and prepares operation that later takes place in one atomic step
- Interference is detected via shared memory
- Retries until not interfered by other operations
  - Can cause starvation

## Non-blocking synchronization

1. Lock-free synchronization
   1. Guarantees atleast one thread makes progress
   2. No undesirable behavior
   3. More difficult to code than lock-based
2. Wait-free synchronization
   1. All threads make progress, no assumption about speed
   2. More difficult to code than lock-free
   3. Better performance than lock-free

The problems with locks include
1. Deadlock
2. Priority inversion
3. Convoying
4. Async-signal-safety
5. Kill-tolerant availibility
6. Pre-emption tolerance
7. Overall performance

Lock-free mechanisms work but are not practical in absence of hardware support.
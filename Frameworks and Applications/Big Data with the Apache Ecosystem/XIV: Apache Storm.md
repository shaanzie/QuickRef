# Apache Storm

Apache Storm is
- Streaming
  - Key enabler of the Lambda Architecture
- Fast
- Scalable
- Fault tolerant

Storm interacts with batch frameworks like Hadoop to allow stream processing of data.

## Conceptual Model

- Tuples
  - Storm is an ident level processing engine
  - A tuple is a unit of work to be processed
  - Immutable ordered set of serializable values
  - Fields must have assigned name
- Stream
  - Core abstraction of storm
  - Unbounded sequence of tuples
- Spout
  - Source of streams
  - Wrap an event source and emit tuples
- Message queues
  - Source of data
- Bolt
  - Core unit of computation
  - Receives tuples and does computation on them
  - Might emit additional tuples
- Topology
  - Specifications in forms of DAGs of Spouts and Bolts
  - Streaming computation

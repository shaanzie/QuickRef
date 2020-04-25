# Scaling Storage and the CAP Theorem

- Types of cloud storage
  - Object storage
  - Databases
  - Key-value stores
  - Document databases
  - Column oriented databases

- The main requirements of a cloud storage are
  - Scaling
    - Functional decomposition - db level
    - Master-slave
    - Vertical partitioning
    - Row partitioning
  - Availability

- SQL based databases
  - Most common data store
  - Data is stored in the form of tables
  - Indexes used to get to location of data faster

- Functional Decomposition
  - Put different databases on different server clusters
- Master Slave Replication
  - Writes go to master
  - Reads to master or slaves
  - Good for read intensive workload
  - Write time increases with number of slaves
- Sharding
  - Database partitioned by rows into multiple disks
  - Shard key used to identify which disk contains the data
  - Round robin on partitioning attributes
  - Range based hash partitioning or directory partitioning
  - Disadvantages
    - Parameters need to be chosen carefully
    - Increasing number of partitions is difficult
    - Increased complexity in changing schema
    - Joins become difficult

- NoSQL Databases
  - Key-value stores
  - Document stores
    - Structure given to values
  - Columnar databases
    - Better for analytics

- Vertical partitioning - HBase
  - Uses vertical partitioning and sharding for scalability
  - Data appended, not overwritten - using timestamps
  - Data stored in column families with collections of related columns
  - Within a column family, sharded by row(key)

- Storage availability is achieved by replications
  - Multiple availability zones per regions, isolated from each other
  - 3 copies

## CAP Theorem

- Fundamental limitation of distributed systems
- No distributed system can satisfy all three properties below
  - Consistency : All operations appear to be serialized on a non-distributed object
  - Availability : Every operation returns a result
  - Partition tolerance : Arbitrary number of messages between service nodes are lost
- Implications
  - Conventional
    - Network partitioning will happen, introducing high latency
    - Cloud apps deal with either non-availability or inconsistency
  - Contra view
    - Focuses only on one cause of storage down time - human error and app error are equally important
    - Traeoffs should depend on system
    - Partitions are rare
    - Next generation DBs are much faster
  
- Relaxed Consistency
  - Weak consistency = system does not guarantee to return consistent results
  - Eventual consistency = If no further updates, system will become consistent
  - Read your writes consistency = A client performing a read after write will always see its own updates
  - Session consistency = Consistency within a session
  - Do not offer network partition

- Handling consistency example
  - BASE : alternative to ACID
  - Eventual consistency model
  - Queueing updates
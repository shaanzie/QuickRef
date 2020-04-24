# OpenStack Swift

- Object storage needed to store unstructured data
- File + Metadata = Object
- Object/Blob Store
  - Similar to GDrive or Dropbox
  - Referenced by URL
- Operations defined against gross collections of bits, regardless of kind of information
- Tenants
  - Customers of the cloud provider
  - For openstack, this would be an account
- The swift blob stores objects as `https://<prefix-url>/<api-version>/<account>/<container>/<object>`.

## Architecture

- Reliable
  - Configurable replica model with zones and regions
  - Easy to use API
  - High concurrency
- Highly scalable
  - Multitenancy - isolated namespaces
- Hardware Proof
  - No single point of failure
  - Assumes unreliable hardware
- The architecture consists of 
  - Application
  - Load balancer
  - Proxy nodes - forwards data to any node
  - Storage node - stores data

## Object Placement and Replication

- Ring consistent hashing
  - Hash disk id to find position of disk in ring
  - Object stored in next disk in ring
  - Disk ID could be IP address, drive name or combinations
- Consistent hashing
  - Mapping between range of hash and a drive can be variable
  - Locating drive for an object requires hashing and look for the next drive clockwise
- Modified consistent hashing addresses these problems with consistent hashing
  - May take time to move a hash range
  - Objects may be marked unavailable
  - Locating takes time
  - Instead, divide hash range into partitions
  - Move partitions from one disk to another
- Partition power = log2(total partitions in cluster)
- Swift divides these stores into regions of low latency
- Availibility zones allow failure control
- Partitions are replicated
- Unique-as-possible algorithm
  - Replicas placed as far from each other as possible
  - If two regions are tied, both are replicas
- This is called ring-building
- Partition-device mapping is called a ring

## Swift Operation

- The proxy contacts a single available storage node and streams back data
  - Prioritizes nearby storage locations
  - Tries alternate replicas when there is failures
  - During writes, it simultaneously streams 3 writes to each storage location
  - There is no master object as such
- The auditor and replicator are background processing
  - Provide active auditing and replication
  - Ask if other servers if they have a copy of this object
  - Replicator pushes object where it is missing
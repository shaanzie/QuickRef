# Resource Allocation

- Creating a VM in OpenStack
  - `nova boot --flavor 2 --image 174e.. "My Instance"`
  - flavor corresponds to ephemeral disk type
- Instance request is done the same way through GUI
  - Flavor defines instance sizes
- Workflow
  - UI to initiate request = Horizon
  - Should this operation be permitted = Keystone
  - On which machine = Nova
  - Decide OS and boot = Glance
  - Storage = Cinder

## Nova

- Component for execution of compute workflows
- Technology agnostic
- Loosely coupled, uses REST
- Controller has to service the request
- Compute nodes also have a component to start and manage the VM
- Components
  - API
  - Scheduler
  - Conductor
  - Nova Cell
  - Queue
  - DB
- Factors to consider when provisioning VMs
  - Hard constraints
    - Number of cores
    - Memory requirement
    - Type of VM
  - Soft constraints
    - Energy efficiency
    - Affinity
    - QoS
    - Load balancing
    - Throughput
- Scheduling is done as filters and weighing

## Cinder

- Cinder Scheduler
  - Chooses backend to place volumes on
  - Choices
    - Simple - least loaded
    - Chance - random
    - Filter - Same as Nova with Chance as a weight scheduler
- Filter Scheduler
  - Drivers report capabilities and state
  - Algorithm
    - Start with all backends
    - Filter out unsuitable backends
    - Sort by weights
    - Return best candidate
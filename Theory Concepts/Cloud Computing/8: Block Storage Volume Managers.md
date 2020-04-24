# Block Storage and Volume Management

- VMs have different types of block storage, broadly classified as 
  - Ephemeral
    - Not permanent
    - Automatically created when VM is created
    - Get deleted when VM is deleted
    - Used for OS, paging, swap, etc
    - Local disk of physical server, cannot be detached
  - Persistent
    - Permanent storage
    - Created as user specs
    - Can be detached and reattached

- OpenStack uses Cinder as the Block storage functioning unit, which adds additional persistent storage to VMs.
  - Can be partitioned, formatted, mounted

- Disk organisation
  - Continuous row of logical blocks
  - Blocks broken into partitions, for error recovery
  - Needs continuity
  - Once created, cannot change

- Filesystems are created on partitions
  - Require formatting
  - One FS per partition
  - Created using a utility like fdisk

- Discontinuous free spaces in a block mapped by partitions can be used for same filesystems with the concept of volumes
  - Volumes virtualise blocks across non contiguous storage partitions
  - Filesystems are created on volumes
  - Volumes can be grown or shrunk

- Paths are configured to interact with the storage blocks
  - Data path
    - On which the data flows from disk to VM
    - VM stores user data here
  - Control path
    - Commands to manage volume

- LVM or a Logical Volume Manager
  - Provides storage virtualisation in the OS
  - Creates logical disks from physical disks
  - FS thinks its running on a physical disk
  - LVM converts block number on logical disk to block number on physical disk

- SCSI or a Small Computer System Interface
  - The commands the actual disk understands
  - Defines how devices communicate with each other via the SCSI bus
  - Format of data transferred
  - Introduces IDs and Logical Unit Numbers for addressing devices

- Working of SCSI
  - Device tries to reserve the SCSI bus
  - Highest priority reserves and becomes the initiator
  - Issues a SCSI command to target (I/O devices, which send responses)

- To run this on a cloud    
  - Add another virtualisation layer
  - Disk driver thinks it is connected to physical disk
  - SCSI command sent to Cloud Storage Virtualisation Layer
  - Converted to command to the physical disk
  - Two layers of virtualisation

- CDB or the Command Descriptor Block
  - Commands defined with CDBs
  - SCSI standards

- For the cloud
  - Send SCSI command as TCP/IP message
  - iSCSI defines the standard format
  - Allows SCSI interface from VM to cloud disks

- iSCSI is Internet Small Computer Systems Interface
  - Storage access over TCP/IP
  - Reuses IP infrastructure

## Cinder : Persistent Storage

- Block storage for Cloud 
  - Uses iSCSI and other protocols
- Cinder instances presented as
  - /dev/vd* on Linux
  - New volumes on windows
- Allows operations such as mount or format
- In cinder
  - Data path
    - Actual transfer between VM and Volume
  - Control path
    - Creates volume
    - Exposes volume to compute node
- Interface
  - Volume create {from image, snapshot, volume}, operations
  - Snapshot operations
  - Backup
  - Quotas
- Cinder only creates the VD and attaches it, the VM reads/writes to the VD just like a normal disk
- Cinder-backup is used to backup data to Swift (OpenStack blob or object storage)
- Driver contains the code needed to talk to a specific storage backend
- The cinder scheduler decides which block storage device to put a volume on
  - Chooses what driver to use
  - Combinations of filters and weights to decide
  - If capacity filter and capacity weigher specified
    - CapacityFilter removes all backends with less than specified capacity (<b>Redundant?</b>)
    - CapacityWeigher picks the backend with largest capacity
  - If VolumeNumberWeigher is specified
    - Picks backend with smallest number of volumes
    - Distributes number of volumes evenly over backends
  - If DriverFilter and GoodnessWeigher specified
    - User defined functions

## Alternate Transport Technologies

- Fiber Channel
  - Storage specific networking
  - Has DNS, Name server
  - Sends SCSI commands
  - High performance
  - Drawbacks
    - iSCSI catching up
    - iSCSI does not need dedicated network
    - iSCSI is less expensive
- iSER - iSCSI extension for RDMS
  - More efficient than iSCSI
  - Copy to buffers eliminated in send operations
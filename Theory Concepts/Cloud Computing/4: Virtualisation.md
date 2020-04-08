# Virtualisation

Virtualisation is a framework or methodology of dividing the resources of a computer into multiple execution environments, by applying hardware or software partitioning, time-sharing, partial or complete machine simulation, emulation, QoS and many others.

The old model was
1. A server for every application
2. Software and Hardware are tightly coupled
3. Underutilised resources introduce real cost into the infrastructure.

The new model is
1. Physical hardware is abstracted by a virtualisation layer, or a hypervisor
2. OS and application encapsulation
3. Seperate OS and hardware break hardware dependencies
4. Optimize utilisation levels

Virtual Infrastructures
1. Bring uniformity
2. Dynamic mapping of compute resources to business
3. Lower IT costs, increased efficiency, flexibility and responsiveness
4. Provisioning new services easily

In order to virtualise, a layer of software is used, called a Virtual Machine Monitor, or a "hypervisor". The hypervisor can run directly on real hardware or on an application on top of a host OS.

Paravirtualisation is a virtualization technique that presents a software interface to that of the underlying hardware. This requires that OS needs to be explicitly ported to run on top of the VMM.

Full virtualisation provides a complete simulation of the underlying hardware. With binary translation, this is able to run existing legacy operating systems without modification.

The VM has 
1. Its own BIOS, with boot options.
2. Networking
   1. Virtual NIC
   2. Connected to virtual switches implemented in the virtualisation layer
   3. Switches have uplink to physical NICs
   4. Backend secured behind firewall using internal-only switches
3. Storage
   1. Simple virtual SCSI host bus adapter to one or more virtual SCSI disks
   2. Kept on physical storage

Usage scenarios for virtualisation 
1. Consolidation
   1. Low utilisation workloads
   2. Efficient resource management
2. Business Continuity Management
   1. Disaster Recovery
   2. OS and application patching
3. Workload Mobility
   1. Packaging of OS, flexibility
4. Development and Test
   1. Rapid provisioning
   2. Wide test range

## Trap and Emulate

The two key methods used by a VM run is trap and emulate. Execution is done on emulated registers and memory, which is slow, but extremely simple.

Some code needs hypervisor intervention, but most of the code is run on the CPU. This is done as
1. System Call
   1. CPU will trap to interrupt handler vector of VMM
   2. VMM jumps back into guest OS
2. Hardware Interrupt
   1. Hardware makes CPU trap to interrupt handler of VMM
   2. VMM jumps to the corresponding interrupt handler of CPU
3. Priveleged instruction
   1. Trap to VMM for instruction emulation
   2. After emulation, VMM jumps back to guest OS.

This gives good performance but
1. Harder to implement
2. Needs hardware support
3. Exists only in modern CPUs

The fundamental assumption for trap and emulate is
1. All sensitive instructions must be trapped
   1. Behavior sensitive - result depends on privilege level
   2. Control sensitive - results could change processor privilege level

## Dynamic Block Translation

Here, a block of binary VM code is taken that's about to be executed, and is executed on the fly to safe code. This safe code is then directly executed on the CPU.

Sensitive operations are translated to hypercalls, where the hypervisor is called to ask for a service, which is implemented as trapping instructions.

This requires no hardware support and delivers better performance than emulation, but is worse than trap and emulate and is hard to implement.

## I/O Virtualisation Models

1. Monolithic Model
   1. Higher performance
   2. I/O device sharing
   3. VM Migration
   4. Cost: Larger Hypervisor
2. Service VM Model
   1. Service VMs handle I/O requests
   2. High security
   3. I/O device sharing
   4. VM Migration
   5. Cost: Low performance
3. Pass-through Model
   1. Directly execute on CPU
   2. Highest performance
   3. Smaller hypervisor
   4. Device assisted sharing
   5. Cost: Migration challenges

## H/W assisted virtualisation

Intel VT-x and AMD-v use root and non-root modes of operation, where each mode has a complete set of execution rings (0 - 3), and new instructions to switch between modes.

The H/W state is duplicated for each operation mode, where the hypervisor runs in root mode and the VMs in non-root.

The KVM way is
1. VMM initialises/modifies VMCS
2. VMM executes vmlaunch/vmresume instruction
3. VM runs until it hits a vmexit condition
4. VMM analyzes and takes action on vmexit

## Memory Virtualisation

Hypervisor manages the physical memory, but the guest OS is given an illusion that it is in control of the memory.

There is a two level address translation that occurs.
1. Shadow page table (Software)
2. Nested/Extended page table (Hardware)

### Shadow Page Table

The hypervisor creates a SPT that maps the guest VA to the host PA directly, by combining the guest page table with the system page table. The hypervisor makes the cr3 point to the shadow table.

Guest OS page tables are read only, and modifications are trapped to the VMM.

However, this has drawbacks
1. Maintaining consistency between guest page tables and SPTs
2. Loss of performance due to TLB flush on every world-switch
3. Memory overhead due to shadow copying of guest page tables.

## Processor Virtualisation

### Problems solved with VT-X

1. Ring Compression
   1. Guest OS runs in ring 3 without compression, but with compression, it can run in ring 0 non root mode.
   2. Guest OS behavior controlled by flags
2. SYSENTER / SYSEXIT simulation
   1. Fast entry and exit to kernel
   2. Without VT-x, these are trapped by hypervisor
3. Interrupt virtualisation
   1. VMCS has control, which causes VMEXIT on interrupt.
   2. Guest setting of interrupt flags need not be trapped
4. Address space compression
   1. Parts of address space shared by hypervisor and OS
   2. Hypervisor traps to access this area
5. Access to privileged state
   1. Upon VMEXIT, hypervisor state is restored

The VT-d is a platform infrastructure for I/O virtualisation
1. Defines architecture for DMA remapping
2. Implemented as platform core logic

## Architectures of some Hypervisors

1. VMWare ESX
   1. Enterprise class hypervisor
   2. vmkernel hypervisor functions
      1. Scheduling
      2. Virtual memory
      3. I/O
   3. vmkernel tech
      1. Trap and Emulate
      2. Binary address translation
      3. Use VT-x or other supports
2. Xen
   1. Paravirtualisation
   2. VMs are called domains
   3. Dom0 filters out all I/O
   4. Uses trap and emulate and BAT
3. KVM
   1. Extends linux kernel to add VMM functionality
   2. Each VM appears as a linux process

## Networking Virtualisation

The hypervisor defines virtual adapters and virtual switches. IP addresses are also allocated dynamically.

1. Xen
   1. Bridged
      1. VM gets IP like physical hosts on the network
      2. Hypervisor transmits packets
   2. NAT   
      1. Private IP range
      2. Hypervisor performs NAT
   3. No switches
2. Microsoft Hyper-V
   1. Hypervisor encapsulates IP as though its from a physical adapter
   2. Virtual switches help connect VMs on the same host
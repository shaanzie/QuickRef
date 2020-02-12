# Containers and Container Namespaces

The key objectives of virtualisation are
1. Access control
   1. Prevent access outside the VM or container
2. Resource sharing
   1. Control resources used by another VM

Containers are used to provide lightweight isolation of Guest OSes instead of VMs.

Linux Containers (LXC) are lightweight VMs without a hypervisor, to use the linux kernel. 
1. Low provision time
2. Near bare metal time performance
3. VM like agility
4. Flexibility
5. Lightweight
6. Open source
7. Supported by any modern linux kernel

All the resources a process can see is called a namespace. This helps restrict objects processable in the container.

The different mount namespace operations are
1. Creation
   1. Create process with namespace 
   2. NEWNS flag enabled as a new child
   3. Child uses mount and unmount
2. Int SetNS
   1. Allows a process to join an existing NS
3. Int Unshare
   1. Allows caller to create new NS

The different types of Namespaces are
1. MNT
   1. Isolate the set of filesystem mounts seen by a group of processes
   2. Different processes have different views of the FS heirarchy
2. PID
   1. Isolate the PID namespace, allowing PIDs to be unique only to that NS
3. NET
   1. Isolation of system resources with reference to networking
4. IPC
   1. Isolate IPC resources
5. UTS
   1. Isolates nodename and domain name, to allow container specific hostnames
6. USER
   1. Isolate the username and group ID namespaces 

Processes in the NS have the illusion that they are the only process in that namespace.

Some commands for namespace operations
```
hostname - current machine name
unshare -u /bin/sh - disassociate current hostname from /bin/sh
hostname <name> - Set new hostname <name>
chroot /mnt command - sees root as mnt, not real root for that namespace
```

Linux chroots change the apparent root directory for processes, but can be escaped. So pivot_root is used instead, which detaches the new root and attaches itself to the process.
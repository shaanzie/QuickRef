# Introduction to Openstack

Openstack is a cloud OS that controls large pools of compute, storage and networking resources throughout a datacenter, all managed and provisioned through APIs with common authentication mechanisms. It's mission is to produce the ubiquitious opensource cloud computing platform that meets the need of public or private clouds regardless of size, by being simple to implement and massively scalable.

The two key design principles of Openstack are
1. Built as a collection of independent services
2. Services provide REST APIs

The architecture is a standard master-slave configuration, with a central controller and distributed workers. The management network connects controllers to compute. When a VM is required, the controller is requested to provision the VM, and is created by the compute nodes. This is done by Nova.

Authentication in Openstack is carried out through keystones, where the user gets a token when they login. The token is submitted with each operation, which authorizes users to perform operations. The UUID token encodes the userid and tenants. But these UUID tokens are inefficient. Instead, users are provided roles, which are a collection of rights that can be assigned to a user, that package all the operations that role can perform. PKI tokens are used for this.
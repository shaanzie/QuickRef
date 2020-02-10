# Introduction to Cloud Technologies

There are three service models for cloud platforms
1. Infrastructure as a Service (IaaS)
   1. The physical hardware is abstracted to virtual servers and virtual storage
   2. Allocated on demand and configured to virtual systems
   3. Greatest flexibility
   4. Least application automation
2. Platform as a Service (PaaS)
   1. Platform built on top of abstracted hardware
   2. Commands to allocate middleware servers
3. Software as a Service (SaaS)
   1. Provides complete application as a service without worrying about the complexities of the hardware.
   2. Least flexibility
   3. Most automation

## Infrastructure as a Service (IaaS)

The IaaS model is

<b><i>The capability provided to the consumer is to provision processing, storage, networks and other fundamental computing resources where the consumer is available to deploy and run arbitrary software, which can include OS and applications. The consumer does not manage and control the underlying cloud infrastructure but has control over OS, storage, deployed applications, and possibly limited control of select networking components.</i></b>

The user of IaaS has single ownership of the hardware infrastructure allocated, and can request resources from the IaaS provider.

Examples: Amazon EC2, Rackspace, RightScale

## Platform as a Service (PaaS)

The PaaS model is 

<b><i>The capability provided to the consumer is to deploy onto the cloud infrastructure consumer-created or acquired applications created using programming language and tools supported by the provider. The consumer does not manage or control the underlying cloud infrastructure including network, servers, OS, or storage, but has control over the deployed applications and possibly application hosting environment configurations.</b></i>

The PaaS provider supports selected middleware, which the cloud user can configure and build on top of this middleware. The PaaS provider maps this new table onto their cloud infrastructure. Subsequently, the cloud user can manage the database as needed, and build applications on top of it.

## Software as a Service (SaaS)

The SaaS model is

<b><i>The capability provided to the consumer is to use the provider's applications running on a cloud infrastructure. The applications are accessible from various client devices through a thin client interface such as a web browser. The consumer does not manage or control the underlying cloud infrastructure including network, servers, OS, storage or even individual application capabilities, with the possible exception of limited user-specific application configuration settings.</b></i>

## Technology Challenges

The main challenges to cloud services are
1. Scalability of compute power and storage
2. New techniques for multi-tenancy, or fine grained resource sharing, are needed for supporting such large numbers of users.
3. Hardware failure and software failure handling
4. Availibility in failure
5. Security
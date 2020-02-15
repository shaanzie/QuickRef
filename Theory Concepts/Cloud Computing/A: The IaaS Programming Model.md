# The IaaS Programming Model - Amazon Elastic Compute (EC2)

Compute as a Service is one of the most popular models for an IaaS platform. 

The Amazon Elastic Compute Cloud (EC2) is one of the most popular CaaS offerings. It allows enterprises to define a virtual server, with virtual storage and networking. This allows high maintenance and scalability benefits for isolated environments.

## Computing resources

The compute resources on EC2, or the EC2 instances, consist of combinations of computing power, and resources such as memory. The computing power is measured in EC2 compute units. 
Amazon provides OS an application softwares in the form of Amazon Machine Images (AMIs). The AMI running on an EC2 instance is also called the root AMI.

EC2 provides the Elastic Load Balancer, which helps balance the load accross multiple servers. The default load balancing policy is to treat all requests as independent, and this scaled the number of servers up or down depending upon the load.

There are two types of block storage resources available: The Elastic Block Service and instance storage.
The Elastic Block Service (EBS) provides block storage for EC2 and has an existence independent of any EC2 instance, which helps persist data. The instance storage is local to the EC2 instance, and this is ephemeral, and exists only as long as the instance exists. In this case, a snapshot may be taken and sent to the S3 bucket for persistence.

In an S3 backed instance, the root AMI is stored in an S3 bucket, which is file storage. Therefore, it must be copied each time to the root device before the instance is booted up. Since instance storage is ephemeral, updates and patches don't last, and these are not attached by default to an EBS backed instance, unlike an S3 instance.

EC2 provides elastic IP addresses, that are independent of any instance, but are associated with the account, and can be dynamically assigned to any instance, which helps implement failover. Route 53 is the DNS server used to allocate this elastic or public IP to a DNS name.

EC2 alows security groups to define network security policies that restrict the ports through which a machine can be accessed. Enterprises who want more control can use Virtual Private Clouds (VPC) that offer
1. the ability to allocate public and private IPs over any range
2. the ability to divide the address into subnets and control the routing between subnets
3. the ability to connect the EC2 network to an Intranet using tunneling


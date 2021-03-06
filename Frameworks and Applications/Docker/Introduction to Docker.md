# Lecture 1

## Why do we need docker?
1. The matrix of hell is a compatibility matrix to be made on every OS to link application stacks to the environment
2. Compatibility was an issue.
3. Modify the underlying frameworks without setting up entire application or service stacks.
4. Docker helps containerize applications.
5. Containers are isolated environments that share the same kernel, unlike virtual machines.
6. Docker uses LXC Containers. 

Sharing a kernel - Run any OS on top of a kernel if its the same type of OS kernel (Linux maybe)
Windows based containers cant be run with linux on it, for example. When a linux container is made to run on windows,
windows makes a linux virtual machine run the docker container.

Unlike hypervisors, docker doesnt run kernels. Docker just containerizes them.

## Containers vs VMs
1. Docker sits on top of the OS, and manages the containers. The Hypervisor in a VM makes an OS on top of the OS.
2. VMs take higher disk space, docker is light.
3. Docker has less isolation because it runs on the same OS kernel, VMs have complete isolation.
4. You usually use containers in VMs to use both technologies.

## How is it done?
1. DockerHub has some images already made and published to use on the fly.
2. docker run ansible, docker run nodejs, etc all work.
3. It can run many instances of the same machine, with a configured load balancer
4. Fault control also works by just destroying instances.

## Containers vs images
1. Docker containers run images in them
2. Images have a package, a template and a plan
3. Devs give the prerequisities and dependencies to Ops, but they cant set up the applications. In docker,
the DevOps work hand in hand through docker images. Ops can just deploy it directly.

# Lecture 2 + install

Docker has two editions
1. Community : Free
2. Enterprise: For companies, management and etc, not free

# Lecture 3

`docker run` -                            runs docker image; looks locally, if not found goes to DockerHub
`docker ps` -                             show running container
`docker ps -a` -                          all containers run or stopped
`docker stop <container id or name>` -    stop container
`docker rm` -                             Remove a stopped container
`docker images` -                         lists all images on the host
`docker rmi <container name>` -           removes the image
`docker pull` -                           pulls image, dont run the container

Unlike VMs, containers are not meant to host OS's, they just host applications. So they run the task and exit.
The container lives only as long as the process inside it is living.

`docker exec` -                           Run a command on a docker container

When a docker container is run in the foreground, the stdout is your only interface when it is running

`docker run -d` -                         Run a command in the background mode to use other things
`docker attach <id>` -                    Go into a container in background mode

# Lecture 4

The tag specifies a version to an image. If no tag is specified, the latest one is used.
By default, docker run does not read a standard input, and runs in a non interactive mode.

The -i parameter allows the container to be run in interactive mode
The application -it allows you to make a pseudo terminal to the docker interactive CLI

Docker host is the system on which the docker image runs
The application listens on a port, and is accessed using this port.
The IP is the docker container's default IP and is an internal IP only accessible on the docker host.
The IP of the docker host can be used, but the port inside the docker container must be mapped to the host of the
machine running the application.

`docker run -p 80:5000` routes all traffic of 8080 to 5000. This allows a lot of instances to be run simultaneously
on the host containers.

Volume mapping is done in docker to persist data on a docker container. -v allows this volume mapping to a persisted 
disk on the system.

Additional details about a specific container are given by `docker inspect <container-name>`

The logs of a containerized application can be viewed through docker logs

# Lecture 5

Environment variables are set using -e with docker. These can configure the application without explicitly editing the
file

These environment variables can be found in the inspect.

# Lecture 6

To create an image, make a file called DockerFile.
Sample DockerFile

FROM Ubuntu

RUN apt-get install python
RUN pip install flask
RUN pip install flask-mysql

COPY ./opt/source-code

ENTRYPOINT FLASK_APP=/opt/source-code/app.py flask run

Then build it it locally using docker build DockerFile -t <path>

`docker push` uploads it to the DockerHub

A DockerFile is structured as INSTRUCTION and ARGUMENT. Here, FROM is an INSTRUCTION and Ubuntu is an ARGUMENT

All DockerFiles must start with a FROM instruction to start from a base OS

The ENTRYPOINT specifies a command to be run when the image is run as a container

Each INSTRUCTION makes a new layer in the container when the docker build command is used.

`docker history <image>` tells you the size taken in each layer.

All layers are cached, incase of failure, or updates, the build takes lesser time.

# Lecture 7

CMD defines the default command to be run in the docker image when a container is made.
For example, the in an Ubuntu DockerFile, CMD bash is used.

Docker does not attach a terminal by default, so we specify an overwrite as `docker run <container> <COMMAND>`

Commands can be given as a JSON format as CMD ["command", "param"] and run with `docker run <container> -t <COMMAND>`

To remove the command from the CLI, specify it in the ENTRYPOINT as ENTRYPOINT ["sleep"] for example.
This allows you to run as docker run sleeper 1 instead of docker run sleeper sleep 1

To configure a default parameter, we use an ENTRYPOINT and CMD, and the CMD is appended to the ENTRYPOINT
Somewhat like a default parameter

`docker run --entrypoint <new command> <container> <params>` modifies the entrypoint given.

# Lecture 8

`docker run <container>` --network specifies the network the container runs on.
1. the bridge is a private network of internal IPs and containers talk to each other using these ports
2. The docker host allows the containers to access containers directly through external ports, but can't run
multiple web containers as all the ports are common
3. none network runs in isolated states

To isolate the containers on a host, docker creates only one bridge. We can make multiple bridges by giving
`docker network create --driver bridge --subnet <mask> custom-name`

`docker network ls` lists the existing networks in the docker host. 

The network settings are seen through docker inspect and check Networks

Containers can reach other using embedded DNS servers, rather than use the internal IP used, as the internal IP might
change on reboot.
Docker allows containers to resolve each other with the container names.

Docker uses network namespaces, which create network spaces for each container. It uses virtual ethernet pairs to
connect containers together

# Lecture 9

`/var/lib/docker` is the filesystem made by docker to store data

Dockerfiles can reuse layers from the cache when a build command is given, to build images faster and saves disk space
A writable layer is used to store files created by the container. 
The image layers are read only and the container layers are read write. The read write layer allows to make copies
to make the read only layer files accessible to this layer

Copy-on-write is used to reduce disk space.

`docker volume create <name>` creates a persistent data volume and can be mounted inside the read write layer by 
specifying -v in docker run 

`bind` mounts a directory from any host file
`--mount` is more verbose, so is used with docker run and specify source and target

Docker uses storage drivers such as AUFS, ZFS, Overlay, etc to make these volumes

Docker chooses the best storage driver based on the underlying OS.

# Lecture 10

`docker compose` creates a config in YAML that encapsulates services to run in a container
`docker-compose up` brings up the docker container and is applicable only when you run the container on a host

When you use docker run, we have to link the different containers deployed.
`docker run --link <container-name:host>` is given to link different applications together

In docker-compose.yml, we give the names of the image, ports and links as properties with the same as keys
and the values as the values you want to associate with that name

To run a docker build, the image is given a value to the path at which the Dockerfile and app code exists

docker-compose version 2 allows you to specify a services properties and put the container spec in that YAML.
A version must be specified in the YAML file as well. It automatically creates a dedicated bridge network and 
sets up communications. So -links becomes obsolete.
Version 2 also allows a depends_on property to a container, to start after the depends_on container is running.

Version 3 comes with support for docker swarm.

In the compose, we make a networks property and add a map of the networks a services it uses.

This can be replaced in the networks options in each container.

# Lecture 11

A registry is where docker images can be pulled from.

# Lecture 12

Docker engine is a host with docker installed on it. 
1. The docker daemon manages the docker objects.
2. The rest API server manages the service APIs on the container
3. The CLI uses the rest API to communicate with the domain.

`docker -H` allows you to run the docker CLI with the daemon on another machine.

Docker uses namespaces to abstract workspaces such as pids, mounts, networks etc.
PID - the init process will have 1 in the container, but a normal PID on the host 
Docker uses cgroups or control groups to control the amount of resources a container can use from the CPU.
`docker run --memory` and `docker run --cpus` can specify the resources 

# Lecture 13

If an application is being loaded intensively, new containers much be deployed to balance the load.
Host health must also be maintained.

Container orchestration solves this using tools and scripts to host containers in a production environment.
It allows you to scale up and down depending on the load on the containers, and allows load balancing, resource Sharing
security and so on.
Docker Swarm, kubernetes and Mesos are used for this.

# Lecture 14

Docker swarm allows you to distribute applications to different hosts for load balancing and scaling.
One host is the master of the swarm and the others are slaves.
docker init initialises the docker master and the commands provided are run on the slaves to link them with the master

Docker services can be used to run specific services to run accross slave nodes

`docker service create --replicas=3 webserver` on the master allows 3 replicas of webserver on 3 different nodes

# Lecture 15

Kubernetes allows high level management of clusters by giving a variety of features.
Kubernetes uses docker hosts to host applications as docker containers.
A kubernetes cluster consists of nodes, with each node having kubernetes, and containers are launched.
Failure control is done by node reassignment.
A master exists with kubernetes control plane, and orchestrates the container design.
The components used are 
API server : Frontend for services to interact with the applications on the nodes
etcd : key-value store for data to manage the cluster, stored on each node
scheduler : distributes work accross nodes
controllers: orchestration when node failure and load 
runtime: underlying software to run containers
Kubelet : agent running on the cluster

`kubectl` is the command line interface to manage and deploy applications and related tasks.
`kubectl run` is used to run an application.
`kubectl cluster-info` gives the cluster info
`kubectl get nodes` gives all the nodes on the cluster.
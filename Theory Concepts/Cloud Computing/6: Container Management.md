# Introduction to Container Management with LXD and Docker

## LXD

LXD is a container hypervisor of sorts, that helps manage running containers on a system. It uses an LXD daemon to provide container management, with provisions for
1. REST APIs - OpenStack
2. CLI
3. User containers
4. Online snapshots
5. Container migration

# Docker

Docker is a tool that creates application containers that have full static application stacks. This allows quick deployment of applications. The key differences between Docker and LXC are
1. LXC is a virtualisation technology that implements namespaces for isolation. Docker is a container management technology that acts as a layer over the LXC for easy usage.
2. LXC containers have no portability, whereas Docker containers are portable.

Docker provides tools to simplify building container images, provides versioning and image-reuse.

Docker images have their specifications stored in Dockerfiles in a YAML format. The image is built from this Dockerfile and usually is only one application.

Docker containers are an image plus a temporary R/W filesystem, which is used as temporary storage and is deleted when a container is destroyed. Multiple containers can use the same image and their own temporary storage. Persistent storage can be done by mounting host volumes into the container's default filesystem using mount.

UnionFS permits layering of filesystems in Docker. It provides a FS interface to the kernel, and provides itself as the kernel's VFS to the filesystems on which it stacks. The `-o cow` option on mount enables copy-on-write, which says that a new file is created when an original file is modified.

The docker infrastructure has a docker client, a docker daemon and a registry. The client issues commands to create and run containers on a host. The docker daemon builds the images and containers and deploys it on the host. The registry acts as a hub to provide docker images to the client and daemon based on the build specification.
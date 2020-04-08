# Introduction to REST

REST stands for REpresentational State Transfer. It is a set of principles that define how Web standards such as HTTP and URIs, are used. The five key principles of REST are
1. Resources
2. Representations
3. Operations
4. Hypertext
5. Statelessness

REST helps build client-friendly distributed systems that are simple to understand and simple to scale.
1. Clients rely on services that behave according to conventions, and that are flexible.
2. Simple and distributed
3. Scaling is easy

## Resources

1. Every resource has an identifier
2. The URL is the unified concept of an identifier on the web
   1. URI identifies a resource by location, name or both
   2. URL is a subset of URI
3. REST says to identify everything worth identifying
4. Resources can be static or dynamic
5. Same resource can be referred to by more than one URI
6. Use full URI namespace for identity
7. An identifier must hide the implementations
   1. Highly readable
   2. Easy to debug
   3. Easy for clients to construct

## Representations

1. RESTful systems empower clients to ask for data in a form that they understand
2. MIME types are requested in large numbers
3. Instead of HTML, a client can request a resource, as XML or JSON.
4. We can use more than 1 URL for different representations of the same resource
5. Abstract resources from representations
   1. Long life
   2. Flexible
   3. Favour client, not developer

## Operations

1. Services broadcast their operations and clients sync.
2. Operation names follow dev's style
3. REST standard ops
   1. GET
   2. PUT
   3. POST
   4. DELETE
4. Small set to keep readability and simplicity
5. A safe method does not modify resources.
6. An idempotent operation has no additional effect if it is called more than once with the same input parameters.
   1. Used in design of network protocols, where request to perform an operation is guaranteed atleast once.
7. GET
   1. Safe
   2. Idempotent
8. DELETE
   1. Unsafe
   2. Idempotent
9. PUT
   1.  Unsafe
   2.  Idempotent
10. POST
    1.  Unsafe
    2.  Not Idempotent

## Hypertext

1. Web servers publish hypertext so that browsers know what to do next.
2. In REST, application state is transferred and discovered within hypertext responses
3. A REST client needs less knowledge about how to interact with any particular service compared to clients that interact with operation centric services.
4. RESTful interaction is driven by hypermedia, not out of band information

## Statelessness

1. REST mandates that state either be turned into resource state, or kept on client. The client is responsible for the application state, and the server for resource state.
2. The server should not retain any communication state with a client beyond a single request.
3. The clients are isolated against changes in the server.
4. It also promotes redundancy, with efficient load balancing
5. Unlocks performance
   1. Reverse proxies
   2. Sit between client and server and cache server responses.
   3. Remove stuff from cache after a time

## Errors

An error can be augmented by sending different error messages based on the operation. HTTP has a well defined set of status codes for error handling.

## Common Objectives to REST

REST is usable for any CRUD, but not for real business logic. There doesn't exist a strong language specification like WSDL. 

REST says nothing about how to maintain state. It is not a good solution for real time systems or bandwidth-constrained systems.
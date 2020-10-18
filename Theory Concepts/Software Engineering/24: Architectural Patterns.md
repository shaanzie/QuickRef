# Architectural Patterns

- Is a proven solution of structuring and functioning of the subsystems that's used earlier.

- Potential solution and starting point.

- Tiered Architecture
  - Single tiered
    - Monolith
    - Single application layer that supports UI, rules and manipulation all in one
    - Used in client-server
  - Two tiered
    - Business rules and UI as part of the client
    - Data retrieval and manipulation is on a separate system
  - Three tiered (State-Logic-Display)
    - Client access business functionality through a user display
    - Business functionality are provided through logic part
    - The data store keeps all the persistent data or states

- Client Server Pattern
  - Client is a single user workstation with presentation and appropriate interfacing
  - Server acts as a backend and processes client requests
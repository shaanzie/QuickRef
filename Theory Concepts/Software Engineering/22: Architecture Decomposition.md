# Architecture Decomposition

- Design issues are chosen to be solved by finding the best option from among the alternatives.

- Architectural conflicts
  - Large grain components improves performance but reduces maintainability
  - Introducing redundancy improves availability but reduces data integrity
  - Localizing safety related features means more communication, giving degraded performance

- Generalised model
  - Understand problem
  - Solve it
  - Evaluate solution

- A backlog is the set of constraints, the context of the problem and the requirements, that define the architecture to be synthesized.

- Design methods
  - Detailed Design Methods support decomposing the components to represent the system requirement
  - Used for development as a hierarchy

- Data flow diagrams (DFD)
  - Structured Analysis (SA) : Logical design drawn as a set of dataflow diagrams
  - Structured Design (SD) : Transforming logical design into a program structure drawn as a set of structure charts
    - Heuristics for this are based on coupling and cohesion
    - Major heuristics concerns choice for top-level structure chart, most often: transform centered
  - Contains the following components
    - External entity: Source and destination of a transaction
    - Processes: Transforms the data
    - Data stores: These lie between processes
    - Data flows: Paths where data travel between processes

- DFDs are made into minispecs
  - Algorithm that models the DFD

- Data dictionary
  - Contents of the DFDs after we are at a logical decomposed state
  - Precise description of the structure of data

- Transform-Centered design
  - Traces input through data flow diagram till it can no longer be considered an input
  - Process in DFD becomes a component of a structure chart
  - Data flow become component invocation
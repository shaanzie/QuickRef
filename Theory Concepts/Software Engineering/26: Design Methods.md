# Design Methods

- Detailed design methods supports decomposing components to represent the system requirement

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
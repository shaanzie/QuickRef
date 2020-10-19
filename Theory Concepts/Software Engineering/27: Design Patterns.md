# Design Patterns

- Design pattern
  - Reusable solution to a recurring problem
  - May be documented descriptively and prescriptively
  - Can be procedural or object oriented

- Procedural patterns
  - Common solutions
  - Type
    - Structural decomposition
      - Breaks down a large system into subsystems
    - Organization of work
      - How components work together
    - Access control
      - Describes how access is controlled, say a proxy
    - Management 
      - How to handle homogeneous collections
    - Communication
      - How two components communicate with each other

- Object Oriented Patterns 
  - Gang of Four patterns
  - Types
    - Creational patterns
      - Focus on creation of objects
      - Eg: Singleton, Builder, Factory..
    - Structural patterns
      - Composition of objects
      - Eg: Adapter, Bride, Facade, Proxy..
    - Behavioral patterns
      - How objects interact
      - Eg: Command, Interpreter, Iterator
    - Distribution patterns
      - Deal with interfaces for distributed systems
      - Eg: Class stubs and skeletons

- Singleton Pattern
  - Involves a static member in the singleton class, a private constructor and a static public method that returns a reference to the static member
  - getInstance exposes the unique instance and returns that instance

- Anti Pattern
  - Patterns describe situations one better avoid
  - Refractoring is applied whenever an antipattern has been introduced
  - Eg: God class, Dead code

- Design Document
  - Architecture diagram
  - Description of components
  - Interaction Diagrams
  - Architectural styles and patterns
  - UI design
  - Detailed design approach
  - Design approaches considered and challenges
  - Design patterns considered and for what reason
  - Requirement Traceability Matrix
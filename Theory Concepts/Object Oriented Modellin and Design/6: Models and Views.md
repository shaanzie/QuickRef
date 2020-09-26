# Models and Views

- Semantic Rules
  - Names: What you can call things, relationships and diagrams
  - Scope: The context that gives specific meaning to a name
  - Visibility: How those names can be seen and used by others
  - Integrity: How things properly and consistently relate to one another
  - Execution: What it means to run or simulate a dynamic model

- Elided: certain elements are hidden to simplify the view
- Incomplete: certain elements may be missing
- Inconsistent: The integrity of the model is not guaranteed

- System architecture view
  - Use case view
  - Design view
  - Process view
  - Implementation view
  - Deployment view

- Views can be 
  - Static
  - Dynamic

- Use case view
  - View from the perspectibe of end users, analysts and testers
  - Static view
    - Use case diagrams
  - Dynamic view
    - Interaction diagrams
    - State chart diagrams
    - Activity diagrams
  - System is
    - Black box
    - Under development
  - Actor
    - Represents a coherent set of roles
    - Interacts with these use cases
    - Can be human or automated
  - Use case
    - Interaction of actors and the system
    - Description of a set of sequences of actions
    - Could have variants
    - System performs actions
    - Yields observable result of value to an actor
  - Precondition
    - Conditions to be satisfied before the case begins
  - Basic Flow/Main Scenario
    - Normal workflow
    - No errors
    - Actors get expected result
  - Alternate Flow
    - Less common interaction done by a user with the system
  - Exception flow
    - Prevents a user from achieving the goal
  - Post conditions
    - The conditions that need to be checked after the case is completed
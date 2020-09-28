# Class Diagram

- An attribute of a class can take a number of distinct values

- If the number of values is fixed, we can implement using a subset of int or enum

- If the number of values can change
  - The behavior in such cases will be littered with selection based on the value of the attribute
  - These break down when the attribute can take a new value
  - Here, we use inheritance

- Knock off if statements based on the value of type
- The base class would be abstract
  - Only specifies interface, but not implementation
  - Implementation defined in derived classes
  - Makes adding a new type easy

- Namespaces are used to qualify names clearly in a specific scope

- Actors do not communicate with each other, they only communicate with the use case

- Stereotypes attach some semantics to the diagram
  - Specified in `<<>>`
  - Can be
    - Include
    - Extend
    - etc

- By looking at the diagram, we can't infer the sequence of operations unambiguously.
  - We don't know when includes occur
  - We don't know when the priority for extending is set

- We use dotted lines for stereotypes, and solid lines for behavior
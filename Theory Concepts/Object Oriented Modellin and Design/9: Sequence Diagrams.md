# Sequence Diagrams

- A sequence diagram is wrt to time and a collaboration diagram is wrt to space

- Sequence captures events in time

- Collaboration diagrams capture time by sequence numbers as well as interaction between different components of the class diagram

- To model the flow of a sequence diagram by time ordering
  - Set the context for the interaction, whether it is a system, subsystem, operation, or class, or one scenario
  - Set the stage for interaction by identifying which objects play a role in the interaction. Lay them out on the sequence diagram from left to right, placing the more important objects to the left and their neighbouring objects to the right
  - Set the lifeline of each object
  - Establish a comprehensibe timeline, from top to bottom
  - Adorn each object's lifeline with its focus of control (Look at different types of adornments)
  - Specify time or space constraints, adorn each message with a timing mark and attach suitable constraints
  - Attach pre and postconditions to each message, to specify flow of control more formally
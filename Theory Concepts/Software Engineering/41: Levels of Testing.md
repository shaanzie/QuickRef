# Levels of Testing

- Determines if system meets needs

- Assessment of whole system behavior
  - Collecting information that directs the product release
  - Discovering bugs that cannot be attributed to individual components
  - Focuses on interface errors

- Unit Testing
  - Test for coding/construction errors before it goes to QE
  - Could be at class levels
  - Could be for
    - Algos and logic
    - Data structure
    - Interfaces
    - Independent paths
    - Boundary conditions
    - Error handling

- Integration Testing
  - Test to verify the interfaces between components against a software design
  - Finds timing and resource contention problems
  - Software components corresponding to elements of the architectural design are integrated in an iterative way either as top down or bottoms up and tested until the software works as a system
  - Options
    - Big bang approach
      - Everything integrated and then system is tested
    - Incremental construction
      - Top down
      - Bottom up

- System Testing
  - Tests a completely integrated system to verify that its compliant with its specified requirements
  - Seeks to detect defects between inter-assemblages and also the system as a whole
  - In context of a functional requirement/system requirement
  - Varieties
    - Smoke and sanity
    - Regression
    - Installation
    - Function and non-functional
    - Destructive
    - Software performance
    - Usability
    - Localization
    - Boundary
    - Startup/shutdown

- Acceptance Testing
  - Runs a suite of tests on the complete system
  - Each test is known as a case, resulting in a pass/fail outcome
  - High level tests
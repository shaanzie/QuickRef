# Testing types

- Black box testing
  - Treats software as a black box without regard to internal structure or logic of implementation
  - Concerned with external behavior
  - Objective is to identify defects in the output, generated due to a result of valid and invalid input

- White box testing
  - Factors in internal logic and structure of code
  - The test specifier uses knowledge of the internal structure of the software to derive test cases
  - Test cases cannot be determined until the code has actually been written 
  - It is testing from a developer's point of view

- Grey box testing
  - Hybrid testing
  - Involves access to internal data structures and algorithms to design test cases
  - Testing done at user or black box level

- Static Testing
  - Check for defects in the software without execution
  - Performed in early stage of development
  - Consists of Reviews and Static Analysis
  - Review
    - Informal
    - Walkthrough
    - Peer review
    - Inspection
  - Static Analysis
    - Code quality
    - Data flow
    - Control flow
    - Cyclomatic complexity

- Dynamic Testing
  - Execution of code analysing dynamic behavior
  - Involves providing input values for the software under test, observation of the output values, which are then analysed
  - Can find complex defects, but time and budget consuming
  - Types of techniques
    - Testing based on techniques
    - Based on how testing is done
    - Levels of testing

- Testing technique based
  - Code based
    - Control flow based criteria
    - Branch coverage
    - Data flow based criteria
    - Statement coverage
  - Fault based
    - Error guessing
      - Most plausible faults
    - Fault seeding
      - Single fault injected into copy of code
      - Run against correct version
      - Fault tolerance
    - Mutation testing
      - Tests seldom-executed code
      - Well defined mutation operators
      - Single statement is changed differently in several copies
      - Tests run against original and mutants
  - Specification based
    - Test functionality based on requirements
    - Equivalence partitioning divides input into partitions from where test cases can be derived
    - Boundary value analysis tests are designed to include representatives of boundary values that are common locations for errors, that can result in software faults
  - SE intuition based
    - Tester's experience
  - Usage based
  - Application domain
    - Knowledge about product domain for testing

- Mode of testing
  - Manual testing
    - Involves testing step by step without scripts
    - Complex tests
    - Slow and tedious
    - Hard to get test coverage
  - Automated testing
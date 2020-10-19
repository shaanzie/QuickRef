# Factors for Effective Coding

- Considerations for effective coding
  - Handling of error conditions
  - Prevention of code-level security breaches
  - Using computational resources of host effectively
  - Code documentation
  - Readable programming
  - Code and system optimization (tuning)

- Standards 
  - Rules which are mandatory
  - Specified by organization
  - Uniform appearance to the codes written
  - Helps in code reuse and finding bugs

- Guidelines
  - Non mandatory rules
  - Practices to be followed
  - Increases readability

- Defensive programming
  - Redundant code is incorporated to check system state after modification
  - Implicit assumptions are tested explicitly

- Secure programming
  - Guard against security vulnerabilities
  - Defects, bugs and logic flaws
  - Approaches
    - Validate input
    - Heed compiler warnings
    - Default deny
    - Adhere to principle of least privilege
    - Sanitize data sent to other system
    - Architect and design for policies
    - Practice defence in depth
    - Adopt secure coding techniques

- Testability programming
  - Add test points
  - Method
    - Assertions
      - Identify out of range or innapropriate values
    - Test points
      - Methods that can be used to set or retrieve current module status and variable contents
    - Scaffolding
      - Code written to emulate a feature of system that the object would call
    - Test harness
      - Code written to drive object modules as if they were part of the complete system
    - Test stubs
      - Code that returns known fixed values that emulates functions
    - Instrumenting
      - Execution logging 
    - Building test datasets
      - Valid and invalid data
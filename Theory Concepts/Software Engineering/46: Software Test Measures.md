# Software Test Measures, Metrics and Reliability Test tools

- Software test metrics are quantitative measures of the testing process indicating the progress, quality, productivity and the degree to which a system posseses a given attribute
  - Done to improve efficiency and effectiveness to make better decisions
  - Program may be evaluated by gathering information on the defects

- Measurements
  - Play a critical role in software quality assurance and testing
  - Used to evaluate the quality of product under test
  - Can support defect analysis, which helps improve quality
  - Can be 
    - Representative of quality
    - Test coverage

- Test related measures can be
  - Product measures (size, complexity, etc)
  - Process measures (number of TCs)
  - Project progress (Time spent)

- Defects are classified by severity as
  - Critical
  - Major
  - Minor
  - Low

- Defect density is a measure of total known defects divided by the size of the software being measured

- Product related measures
  - SLOC (Size in lines of code)
  - Fault density (Ratio of number of faults to size of program)
  - MTBF (Mean time between failures measured in hours)
  - Failure rate (Inverse of MTBF)
  - Defect distribution (% of defects attributed to specific phases in SDLC)
  - Defect density of modules (The ratio of faults in module to total faults)
  - Defect leakage (Test efficiency = (Total defects in UAT / Total defects before UAT) * 100)
  - Percent test coverage
  - Percent injected fault discovered
  - Mutation score
  - Percent completed and percent defects corrected
  - Defect removal effectiveness
  - Reqiuirement compliance factor
  - Defect discovery rate
  - Defect removal cost
  - Cost of quality

- Software reliability is the probability of failure-free software operation for a specified period of time in a specified environment

- Test Driven Development (TDD)
  - First write tests, then do design
  - Steps
    - Add a test
    - Run this and the earlier tests, and see that the system fails
    - Make small change to make the test work
    - Run all tests again
    - Refactor system to improve design and remove redundancies

- Selenium offers 4 main things
  - Selenium IDE
  - Selenium RC
  - WebDriver
  - Grid

- Advantages of Selenium
  - OpenSource
  - Extensible
  - Can run tests across different browsers
  - Supports various OS
  - Supports mobiles
  - Can execute tests in parallel

- Disadvantages of Selenium
  - Can only test web apps
  - No built in object repository
  - Automates at slower rate due to thrid party IDE
  - Data driven testing more cumbersome
  - Cannot access elements outside of the web application
  - No official user support is being offered

- JUnit
  - Simple framework to write repeatable tests
  - Unit testing framework for Java
  - No need to manually verify and tally results
  - Provides the following important features
    - Fixtures
    - Test suites
    - Test runners
    - JUnit classes

- Annotations in JUnit
  - @Before - used to execute something as a precondition
  - @BeforeClass - used to execute something before all test cases
  - @AfterClass - Used to execute something after all test cases
  - @Ignore - Used to ignore some statements during execution

- Advantages of JUnit
  - Alternate front ends to display results of tests are available
  - Seperate class loaders for each test
  - Provides standard resource initialisations
  - Standard asserts
  - Integration with popular tools

- Disadvantages
  - Cannot do dependency testing
  - Not for high level testing
  - Large test suites
  - Cannot test various JVMs at the same time

- JMeter
  - Tests load test functional behavior and measures performance
  - Originally designed for testing web applications but has expanded to other test functions
  - Run on any environment with JVM
  - Simulates a group of users sending requests to a target server
  - Elements of JMeter
    - Thread Group
    - Samplers
    - Listeners
    - Configuration
  - Advantages
    - OpenSource
    - Friendly UI
    - Platform independent
    - Multi threaded
    - Highly extensible
    - Visualise test result
    - Unlimited testing capabilities
  - Disadvantages
    - Complex scripting
    - No network visualisation
    - Single normal configuration machine not sufficient
    - Does not support AJAX or web elements
    - Very limited realtime testing
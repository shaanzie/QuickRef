# SCM Roles and Activities

- Roles
  - Configuration manager
    - Select right CIs
    - Define procedures for releases
  - Change Control Board member
    - Responsible for approving/rejecting change requests
  - Developer
    - Creates versions triggered by change requests or the normal activities of development
  - Auditor
    - Responsible for validating the processes followed for selection and evaluations of promotions for release
    - Ensures consistency and completeness of a release

- SCM planning
  - Done by configuration manager
  - Gives a SCM Plan
    - Defines CIs which need to be managed
    - Naming scheme
    - Who takes responsibility of CM and baselines
    - Policies for change and version control
    - Tools to assist CM process and their limitations
    - Configuration management database to record configuration information

- Activities associated with SCM
  - CI identification
  - Build and Install management
  - Branch management
  - Version management
  - Defect management
  - Change management
  - Promotion management
  - Release management

- Build management
  - Converts source code to software artifacts
  - Automated compiling, building and testing
  - No need to recompile files that are not changed
  - Build process
  - Types of build
    - Full build
    - Incremental build
  - Build triggers
    - Manual
    - Scheduled
    - Source code repository
    - Post process

- Install management
  - First interaction developers have with new user
  - May involve customizations for localizations
  - Automation needed
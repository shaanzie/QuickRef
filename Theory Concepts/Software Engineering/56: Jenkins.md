# Jenkins

- Jenkins is an open source automation tool built for continuous integration
  - Generates test reports
  - Integrates with VCS
  - Pushes to various artifact repos
  - Deploys directly into production
  - Etc

- Steps
  - Developers commit changes to a source code several times
  - Every commit to the repo is built
  - This allows the teams to detect problems early
  - There are several other tools that depend on CI like
    - Deploying build on test server
    - Providing results to the right team

- Two main features of deployment
  - Automated : Plugins transfer build files to server after successful build
  - CD where Jenkins automates integration to testing
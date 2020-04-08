# Microservices

Monolithic web applications are difficult to modify as the code becomes larger. Modularity is required for better code readability and allows clear functionality specifications for the whole application stack. Microservices are small and easy to code and deploy. Each microservice supports only one functionality and provides storage as a shared state.

Each sub-application is packaged such that it has
1. Its own GUI
2. Its own logic
3. Its own database
4. Its own definition of a REST API

The API gateway facilitates communication to these REST API endpoints from a client requesting the microservice. This potentially allows for large scaling and better code accessibility.
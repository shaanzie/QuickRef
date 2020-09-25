# Introduction to OO

- Encapsulation
  - Put things together
    - Attributes
    - Behavior
  - May have access control
  - Not a security feature
  - Is a maintenance feature

- The Golden Rule
  - Hide the implementation
  - Expose the interface

- Composition
  - An object of a class is a member or part of another class
  - Is a reuse mechanism
  - Is also called aggregation or layering or containment
  - Prefer composition over inheritance
  - Composition could be done by
    - Value
    - References
    - Pointers

```
// Person has a name
class Person 
{
    Name name;      // By value
    Name *pname;    // By pointer
    Name& rname;    // By reference : const pointer
};

class Name 
{

};
```

- Inheritance
  - Is a relation between classes
  - Creates class hierarchy
  - Not a reuse mechanism primarily
  - Can be a reuse at class level, but that's about it
  - Basic idea
    - Share the interface
    - Avoid if statements based on value of a type
    - Avoid brittle code
# Polymorphism

- Polymorphism
  - Means many forms
  - Same interface, different implementation
  - Implemented using virtual table and virtual pointers

- Liskov's property of substitution:
  - Interface of the base(generalised) class should be supported by the derived(specialised) class.
    - Derived class may use the behavior of the base class by default 
    - Derived class may modify the behavior of the base class (Overriding)
  - Can substitute an object of a base class by an object of the derived class

- Polymorphism is 
  - Replacing an object of the base class by an object of the derived implementing a new behavior
  - It is dispatched to the method of the object of the class
  - Dynamic dispatch: Looking at compile time code, we cannot know which variant of the overloaded function is being called

- A diamond denotes composition in a UML diagram

- Polymorphism is implemented using vtbl and vptr concepts
- There is no free lunch
  - Pointer per object
  - Table per class
  - Extra dereferencing at runtime
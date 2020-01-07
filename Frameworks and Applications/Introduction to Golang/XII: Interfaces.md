# Interfaces in Go

Interfaces are a type at the end. Interfaces don't describe data, they describe behavior of objects. So they store method definitions instead.

Interfaces are not explicitly implemented, but are inferred implicitly. If a concrete type needs to be wrapped by an interface, the interface can implicitly latch to this concrete type if defined as the interface of a type defined.

An empty interface is an interface with no methods. This is given by `var obj interface{} = new Class()`. This is used to cast any generic object to this class, to make them type compatible.
But this causes problems, as the obj cannot be used. To make this obj useful, some definitions must be provided to the obj or a reflector is used to extend its functionalities.

`switch i.(type)` is called a type switch, where each of the cases represent a datatype. Here, i is an empty interface, and can provide generic interface checks for dynamic execution.

Some of the best practices in Go interfaces are
1. Use many, small interfaces
   1. io.Writer, io.Reader, interface{}
2. Don't export interfaces for types that will be consumed
3. Export interfaces for types that will be used by package
4. Design functions and methods to receive interfaces whenever possible

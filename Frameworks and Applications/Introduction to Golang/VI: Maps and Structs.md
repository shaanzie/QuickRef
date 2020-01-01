# Maps and Structs

A map is a key-value structure. This can be defined as `a := map[string]int{"C" 1, "D" 2}`.

delete(key) can be used to directly remove keys. map, ok can be used to check for presence of a key stored in the ok variable. It is usually used just for the test of the existence of the key.

A struct is defined as

`type Doctor struct {number int     actorName string}`

This is used to store variables of different types. This also follows standard positional syntax. Named constructs can be supported by explicitly mentioning the variable to which a value is bound in a struct. This syntax is usually preferred over the standard positional syntax.

For a structure to be available to other packages, all the underlying variables of the struct must be exportable, using capitalised naming.

Anonymous structures are structures defined usually for one variable use. This can be referred to as `aDoctor := struct {name string} {name : "John Doe"}` where the first {} pair allows the definition of the structure and the next {} the values assigned to that anonymous structure.

Struct are value types, unlike maps. These refer to independent data structures, and only copies are sent around if the reference is not sent.

Go does not have an inheritance model for classes, but has composition. IS-A relationships are not possible due to the construct of Go. Composition however, is supported using embedding. This can be done by declaring a structure type to contain another structure.

`type Animal struct {Name string    Origin String}`

`type Bird struct {Animal    Speed float32}`

Here, bird is an independent structure, with an animal struct embedded in it, which implies a HAS-A relationship.

A tag can be used to allow constraints on the values assigned to the variables of a structure. This is done through backticks(`).
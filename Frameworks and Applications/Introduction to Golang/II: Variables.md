# Variables in Go

## Variable Declaration

Variables can be declared in 3 different ways

1. var i int - variable i of type int
2. var i int = 32 - initialise in the same line
3. i := 42 - Go dynamically determines what datatype it is

The identifier %v is used for value in prints, and %T for the type. The first declaration asserts more control, but is logically similar to the 3rd.

Implicit conversion of datatypes is not allowed in go. var i float32 = "foo" returns an error.

A way of decalaring multiple variables is
var (
    actorName string = "foo"
    companion string = "var"
    season int = 11
)

In go, reassigning variables is not allowed in the same scope. For different scopes, the value of the local scope takes precendence. This is called shadowing.

Declared variables that are not used throw errors in Go. This is done for voluminous applications with spurious variables.

Lowercase variables are scoped to a package. If they are uppercase, the variables are exposed to all global packages, which works similarly to exporting variables, as done in Java.

## Naming Conventions

1. The name of the variable must represent the lifespan of the variable.
2. The name must dignify the meaning of where the variable is used.
3. Acronyms are kept uppercase for better code readability.

## Variable conversions

var j float32 = float32(i) is used to explicitly convert datatypes. This follows the standard data loss patterns seen in explicit type conversions. Implicit type conversions just throw errors in case of loss of indormation.

An int converts to string by using unicode information, which needs to be kept in mind. A standard string conversion package is used instead to convert these integers to strings, such as itoa and atoi.
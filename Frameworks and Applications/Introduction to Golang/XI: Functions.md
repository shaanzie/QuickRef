# Functions in Go

Functions are usually defined as `func <name>( <parameters> ) <return type> { statements }`.

Functions have a static execution path. Variables to be used in a function can only be passed through parameters. These variables are called arguments. These arguments are positional, so the order of passing parameters is based on the function signature.

Go also supports pass-by-value and pass-by-reference, where passing by value makes a copy of the arguments, whereas passing by reference is used to send memory locations referring to the address of the parameter passed.

Variadic parameters can also be passed to functions using ellipses(...) that tells the Go runtime to wrap all these objects into a slice and send it to the function.

Functions in Go support multiple return values as well, such as an error object, generating this error object as an Errorf() object of the fmt package.

An anonymous function can be declared as `func() { // statements } ()`.
The ending () invoke the function.

This may, however, lead to undefined behavior in asynchronous code. So to mitigate that, we use `func(<parameters>) { // statements } (<argument>)`.

Functions can also be assigned to variables as `var f func() = func() { // statements }`.

Methods are just functions where the function is provided a context to execute in. An example of this is `func (o object) func-name() { // statements }`. This can be invoked by `o.func-name`.

Functions in Go allow automatic promotion from stack memory located variables to main memory variable locations for use of those function-local variable to the outside scopes as well.

# Control Flow

Defer is used to allow a construct to delay the instruction till the return statement is encountered. The latest defer is executed first.
`defer statements` is the general syntax. Refer to the defer example to see it work.
When a statement has a variable redefined after in the program, the defer takes the value of the variable at the time defer is called.

Panic is used to allow exception handling in Go, just like a try catch block. But panic runs regardless of condition, and directly throws an error. Refer the example program to see how panic works.
Panics are not fatal, but exit only when the panic rides up to the uppermost package.
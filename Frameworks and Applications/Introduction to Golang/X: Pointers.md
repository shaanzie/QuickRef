# Pointers in Golang

Instead of making copies of an object, pointers are used to refer to the same memory address of a variable. Pointers are declared as `var b *int = &a`.
Pointer arithmetic works pretty much the same way as the C/C++ pointer construct.

Pointers can also be created using the new function. This works as `var ms *myStruct = new(myStruct)`.

An unintialised pointer is dynamically initialised to a value nil, which is the Go equivalent of NULL. However, slices initialised as copies of each other share the same address space. Arrays make copies, and make separate address spaces for copies. Maps also share the same address space. As a shorthand, any type whose size is not known at compile time shares its address space with all variables that are copies of it.
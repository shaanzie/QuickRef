# Conditional statements

The general syntax of an if statement is usually
`if condition { statements }`

The condition can also be used to generate variables to use in the statements. For example, this statement is valid:
`if pop, ok := myMap['Hello']; ok { fmt.Println(pop) }`

The conditional statements in Go also follow short circuiting, which is similar to the C construct where if a condition in a set of or conditions passes, the other expressions in the condition are ignored and the test is passed.

Switches are used to evaluate multiple if-else constructs. The syntax is similar to that of C/C++ where
`switch a {case 1: statement    case 2: statement}`

Falling through is not allowed in Go, and each case inherently has a break at the end. But cascading cases is allowed, where the case for multiple values can be defined in one line.
The cases also need to be mutually exclusive, else, Go throws an error.
Just like in if, the switch condition can be used to assign variables. 

Switch also has a tagless syntax where, we can give more verbosity to the standard switch syntax. This is done by `case i<=10 : statement`.

Type switches are used to handle different types of a variable sent to the switch. For example, if a variable is defined as an interface object, it can be used in a type switch to do different operations based on the type taken by the variable in run time.

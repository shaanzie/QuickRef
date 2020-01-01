# Constants in Go

## Naming constants

All constants are prefixed with const. The naming conventions do not start with capitals, as this means it will get exported. So camelcase is used. 

## Typed constants and Enumerations

Typed constants are referenced just as normal variables. An example would be
const myConst int = 42
Reassigning myConst would give an error. 
Constants can also not be used to set constants whose values are only determined at compile time.

Constants can be shadowed just like variables, where local scope takes highest precendence in the event of multiple constants with the same name. 

Also just like variables, constant types can be inferred by the compiler at runtime. This is because all undeclared types are replaced with their literal values in each position and adapted to the operation.

Constant blocks can be used to group together constants as
const (
    a = iota
    b = iota
    c = iota
)
If no value is assigned to b and c, the pattern can be inferred by the compiler, as an enumeration. But this iota value is applicable only to that const block. 
For example,
const (
    a = iota
    b
    c
)
This would give a = 0, b = 1 and c = 2. But since we do not want a to be the 0 value, we declare an error const as err = iota. We can also just use a _ value (underscore) which discards the 0 value of the const block.

Using a = iota + 5 is perfectly acceptable at compile time, giving flexibility to enumerations as fixed offsets.
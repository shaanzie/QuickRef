# Looping

The only looping construct in Go is the for loop. An example is 
`for i := 0; i<5; i++ { statements }`

We cannot use i := 0, j := 0 due to the non-existence of the comma operator in Go. But doing i, j := 0, 0 is allowed.

To mitigate the problem of while-like constructs, Go allows this syntax
`for i < 5 { statements  i++ }`

To allow the do-while construct, we can omit the condition entirely in the for syntax, but put a break statement in the for loop.
`for { statements condition { break } }`

Iterating over collections can be done by a for range loop where 
`for k, v := range <collection> { statements }` 
where the items in the slice are iterated one by one as key-value pairs. If we do not use the value, an error occurs. So we skip the v variable in the for. But if we need only the value, we cannot omit k. So we use an underscore instead of k as _, v instead.
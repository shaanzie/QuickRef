# Arrays and Slices

Arrays are declared as arr := [3]int{97, 85, 93} for example. This gives an array of 3 integers.

Arrays of arrays can be made as well as 
var arr := [3][3]int {[3] int{0, 0, 0}, [3]int{0, 1, 0} [3]{1, 2, 3}}

In Go, arrays are referenced as variables. Copies are made that do not refer to the same array for each copy. To use the same reference to the array, we use pointers as addresses to the array.

Arrays are not that efficient in Go because the size of the array needs to be known at compile time. So a slice is used as a := []int{1, 2, 3}.
The slice is just a projection of the array over which the slice exists. The cap() or capacity function tells the maximum capacity of the underlying array.

Slices can be created by normal python syntax as well, as b := a[:3] which gives the slice of the elements up until the 3rd last element.

make() allows a slice to be created as the first parameter takes the size and type of the slice and the second the length of the size. A third argument sets the capacity of the slice. When the capacity is omitted, it just behaves as a normal array.

The append() function takes the slice and the element to be appended to the slice. When this happens, Go creates a new array for this resize. This operation is very expensive, and the make option is used instead. Append can also be used to append slices directly.

Deleting elements is done by appending slices from both sides.
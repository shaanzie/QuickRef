# Primitives in Go

## Boolean Types

var n bool = true is the standard declaration for the boolean primitive.
Initialising a variable always defines the variables as the 0 value. For example, the zero value for bool is false.

## Numeric Types

The 0 value for all numeric types is the normal 0 value.
The main numeric types available in Go are signed and unsigned integers, and these can be

1. 8 bit
2. 16 bit
3. 32 bit
4. 64 bit
Go does not allow operations between conflicting integer types. In this case, explicit conversions must be defined by the users.
These integers also support binary operations on these integers.

The other numeric type is floats and these can be float32 or float64, to represent decimals. This can be declared using the exponential E notation as well.

Complex numbers can be used as well in Go, using i as a suffix to the imaginary component of the number, defined as a complex128 number.

## String Types

Strings in Go are aliases for bytes, so accessing s[2] gives a uint, and not a character. This also means that s[2] = "u" is an invalid assignment. But concatenation is allowed. This also allows strings to be converted to byte arrays for sending them using compression. 

## Rune Types

This represents utf-32 characters. A character in utf-32 format can vary from 1 to 32 bytes, which makes it tricky to work with runes. Runes are declared using single quotes. These are usually int32 aliases, allowing type aliasing for any character to integer.
var r rune = 'a' gives 97 in int32 format.

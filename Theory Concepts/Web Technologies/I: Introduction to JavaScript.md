# Introduction to JavaScript

Objects are the central part of the language. Functions are also represented as objects, making them first class functions. Reference types are stored as objects, which refer to locations in memory. Primitive types can be treated as reference types in order to make the language more consistent. Primitive values are stored directly on the variable object with a scope, while references are pointers to variable objects. These primitive types are not objects, rather, JS makes them look like objects for a consistent experience.

An object is an unordered list of properties consisting of a name and a value. If the value is a function, it is called a method. There are a couple ways to create or instantiate objects, but the main way is through constructors
1. Begin with a capital letter
2. Returns pointer to the object variable, does not return the object (primitive returns the variable directly)

## Functions in JS

The [[Call]] property of the function is unique and indicates that the object can be executed.

The this object is very powerful in defining generic functions. This can also be changed in the program using three methods
1. call(value to which this should be equal, <parameter list>)
   1. Applies this to be the value while calling the function
   2. func.call("Hello", 1, 2, 3)
2. apply(value, <array of parameters>)
   1. Same as call(), but takes only 2 parameters, where second parameter is an array of function parameters
3. bind()
   1. Same as apply(), but binds the this object to the specified value

## Understanding Objects

The `in` operator is used to check for the existence of a property in an object. It does not evaluate the property, but just checks its existence. The `delete` property is used to delete key/value pairs from the property hashtable.

There are two types of properties
1. Data properties
   1. Contain values
2. Accessor properties
   1. Define functions to call when a property is read, and a function to call when the property is written to (Getters and Setters)
   2. Use get func1() and set func1() keywords

## Constructors and Prototypes

The `instanceof` operator deduces the object's type.

Usage
```
console.log(person1 instanceof Person);         // true
```

Calling return inside a constructor will return an object if the returned value is an object, or is ignored if a primitive is returned. If the new operator isn't used in the constructor call, the Object type inherits the value.

A prototype acts as a recipe for objects. An instance keeps track of its prototype through an internal property called [[Prototype]], which is a pointer to the prototype object the instance is using. If a value is not found in the immediate object, it checks the prototypes recursively upwards. The top level properties can, however, be overriden by the objects using them, by shadowing.

## Inheritance

```
var book = {
    title: "Principles"
};
```
can be written as 
```
var book = Object.create(Object.prototype, {
    title: {
        configurable: true,
        enumerable: true,
        value: "Principles",
        writable: true
    }
});
```
Object.create(prototype, propertiesJSON) creates an object with the prototypes and properties mentioned.

Prototypal inheritance occurs when objects share the same prototype of some parent. This causes the parent's prototype to be inherited by the object, along with the object's other functions.
```
Square.prototype = new Rectangle();
Square.prototype.constructor = Square;
```

Constructor inheritance is done when the Object.create() is called to create a constructor with the custom prototype. Using call and apply, constructor stealing can be done to call supertype constructors.
```
function Square(size) {
    Rectangle.call(this, size, size);
}
Square.prototype = Object.create(Rectangle.prototype, {
    constructor: {
        configurable: true,
        enumerable: true,
        value: Square,
        writable: true
    }
});
```
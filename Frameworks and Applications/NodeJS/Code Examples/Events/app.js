const EventEmitter = require('events');
const eventEmitter = new EventEmitter();

eventEmitter.on('tutorial', () => {

    console.log('tutorial event has occured');

}) // on takes listener and when the event occurs

eventEmitter.emit('tutorial'); // This is when the event gets triggered

// To pass arguments

// eventEmitter.on('tutorial', (num1, num2) => {
//     console.log(num1 + num2);
// });

// For custom event handling

class Person extends EventEmitter{
    constructor(name){
        super();    // Allows the use of this property
        this._name = name;
    }

    get name(){
        return this._name;
    }
}

let boy = new Person('boy');
boy.on('name', () => {
    console.log('My name is ' + boy.name);
});

let girl = new Person('girl');
girl.on('name', () => {
    console.log('My name is ' + girl.name);
});

girl.emit('name');
boy.emit('name');

// Events are executed synchronously, where events are executed in the order of emission
const sum = (num1, num2) => num1 + num2;
const PI = 3.14;
class SomeMathObject {
    constructor(){
        console.log('Object Created');
    }
};
// sum(1,2); // Needs to be exposed for other files

// One way

// module.exports.sum = sum;
// module.exports.PI = PI;
// module.exports.SomeMathObject = SomeMathObject;

// The cleaner way

module.exports = {
    sum : sum,
    PI : PI,
    SomeMathObject : SomeMathObject
};
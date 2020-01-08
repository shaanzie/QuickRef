// This module is used to get user input

const readline = require('readline');
const rl = readline.createInterface({input : process.stdin, output : process.stdout}); // Config file

let num1 = Math.floor((Math.random() * 10) + 1);
let num2 = Math.floor((Math.random() * 10) + 1);
let ans = num1 + num2;

rl.question(`What is ${num1} + ${num2}?\n`, (userInput) => {
    // console.log(userInput);

    if(userInput.trim() == ans)    // Use trim always to remove trailing whitespace
    {
        rl.close();
    }
    else {    
        rl.setPrompt('Incorrect response, please try again! \n');
        rl.prompt();
        rl.on('line', (userInput) => {  // Infinite loop until the answer is correct
            if(userInput.trim() == ans)
                rl.close();
            else {
                rl.setPrompt(`Your answer of ${userInput} is incorrect, try again! \n`);
                rl.prompt();
            }
        });
    }
});

// Application keeps running after input is taken, so the readline interface must be closed.

rl.on('close', () => {
    console.log('Correct!');
});

// This works as rl extends the EventEmitter class
const fs = require('fs');

// create a file
fs.writeFile('example.txt', 'this is an example', (err) => {
    if(err)
        console.log(err);
    else
        console.log("File Successfully Created!");
});

// Read a file

fs.writeFile('example.txt', (err) => {
    if(err)
        console.log(err);
    else{
        console.log("File Successfully Read!");
        fs.readFile('example.txt', 'utf8', (err, file) => {
            if(err)
                console.log(err);
            else {
                console.log(file); // Buffer stream printed when encoding type is not defined
            }
        });
    
    }
});

// Renaming file

fs.rename('example.txt', 'example2.txt', (err) => {
    if(err)
        console.log(err);
    else {
        console.log("Success!");
    }
});

// Appending to a file

fs.appendFile('example2.txt', 'Something being appended', (err) => {
    if(err)
        console.log(err);
    else {
        console.log("Success!");
    }
});

// Delete a file

fs.unlink('example2.txt', (err) => {
    if(err)
        console.log(err);
    else {
        console.log("Success!");
    }
});
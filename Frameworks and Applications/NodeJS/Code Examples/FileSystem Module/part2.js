const fs = require('fs');

// Make directory
fs.mkdir('tutorial', (err) => {
    if(err)
        console.log(err);
    else{
        console.log('Folder made');
    }
});

// Delete directory

fs.rmdir('tutorial', (err) => {
    if(err)
        console.log(err);
    else{
        console.log('Folder deleted');
    }
});

// Create folder and a file inside the folder

fs.mkdir('tutorial', (err) => {
    if(err)
        console.log(err);
    else{
    
        fs.writeFile('./tutorial/example.txt', 'Hello World', (err) => {
            if(err)
                console.log(err);
            else{
                console.log("Success!");    // rmdir won't work here, as the folder is not empty
            }
        });
    }
});

// Reading the directory structure

fs.readdir('tutorial', (err, files) => {
    if(err)
        console.log(err);
    else{
        console.log(files); // Array of files, can be used to sequentially delete all files
    }
});
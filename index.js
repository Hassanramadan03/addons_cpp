const addon = require('./build/Release/addon');

// Call the HelloWorld function with an array of numbers
const arr = [1, 2, 3, 4, 5];
const result = addon.helloWorld(arr);

// Print the result
console.log(result); // Output: 15
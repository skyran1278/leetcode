// Problem 4 - Hoisting
// Write some example(s) to explain the concept of hoisting

/**
 * You can call a function before it appears in the code.
 */
sayHi(); // Works!

function sayHi() {
  console.log('Hi');
}

/**
 * var is hoisted but initialized as undefined
 */
console.log(a); // undefined
var a = 10;
console.log(a); // 10

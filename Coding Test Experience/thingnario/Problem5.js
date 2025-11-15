// Problem 5 - var, let and const
// Write some example(s) showing the difference between the above three.

/**
 * Scope difference (function vs block)
 */
if (true) {
  var a = 1;
  let b = 2;
  const c = 3;
}

console.log(a); // 1   (var escapes the block)
console.log(b); // ❌ ReferenceError
console.log(c); // ❌ ReferenceError

/**
 * Redeclaration behavior
 */
var x = 10;
var x = 20; // ✓ allowed
console.log(x); // 20

let y = 10;
let y = 20; // ❌ SyntaxError

const z = 10;
const z = 20; // ❌ SyntaxError

/**
 * Reassignment
 */
let count = 1;
count = 2; // ✓ allowed

const PI = 3.14;
PI = 3.15; // ❌ TypeError (cannot reassign)

var n = 5;
n = 6; // ✓ allowed

/**
 * Hoisting differences
 */
console.log(a); // undefined
var a = 100;

console.log(b); // ❌ ReferenceError (TDZ)
let b = 200;

console.log(c); // ❌ ReferenceError (TDZ)
const c = 300;

/**
 * var attaches to the global object (in browsers)
 */
var dog = 'woof';
let cat = 'meow';

console.log(window.dog); // "woof"
console.log(window.cat); // undefined

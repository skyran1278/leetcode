// URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string. (Note: If implementing in Java, please use a character array so that you can perform this operation in place.)
// EXAMPLE
// Input: "Mr John Smith     ", 13
// Output: "Mr%203ohn%20Smith"
const URLify = (str, len) => {
  let newStr = '';
  for (let i = 0; i < len; i++) {
    if (str[i] === ' ') {
      newStr += '%20';
    } else {
      newStr += str[i];
    }
  }
  return newStr;
}

const URLify2 = (str, len) => {
  return str.trim().replace(/ /g, '%20');
}

console.log(URLify('Mr John Smith     ', 13));
console.log(URLify2('Mr John Smith     ', 13));

console.time('URLify');
for (let index = 0; index < 10000000; index++) {
  URLify('Mr John Smith     ', 13)
}
console.timeEnd('URLify');

console.time('URLify2');
for (let index = 0; index < 10000000; index++) {
  URLify2('Mr John Smith     ', 13)
}
console.timeEnd('URLify2');

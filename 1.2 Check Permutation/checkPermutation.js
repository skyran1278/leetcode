// Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.
const checkPermutation = (str1, str2) => {
  if (str1.length !== str2.length) return false;
  const str1Arr = str1.split('');
  const str2Arr = str2.split('');
  const str1Obj = {};
  const str2Obj = {};
  str1Arr.forEach((char) => {
    str1Obj[char] = str1Obj[char] + 1 || 1;

  })
  str2Arr.forEach((char) => {
    str2Obj[char] = str2Obj[char] + 1 || 1;
  })
  for (let key in str1Obj) {
    if (str1Obj[key] !== str2Obj[key]) return false;
  }
  return true;
}

// Solution #1: Sort the strings.
// Time Complexity: O(n log n)
// Space Complexity: O(1)
const checkPermutation1 = (str1, str2) => {
  if (str1.length !== str2.length) return false;
  return str1.split('').sort().join('') === str2.split('').sort().join('');
}

// Solution #2: Check if the two strings have identical character counts.
// Time Complexity: O(n)
// Space Complexity: O(n)
const checkPermutation2 = (str1, str2) => {
  if (str1.length !== str2.length) return false;
  const charCount = {};
  for (let i = 0; i < str1.length; i++) {
    if (charCount[str1[i]]) {
      charCount[str1[i]]++;
    } else {
      charCount[str1[i]] = 1;
    }
  }
  for (let i = 0; i < str2.length; i++) {
    if (charCount[str2[i]]) {
      charCount[str2[i]]--;
    } else {
      return false;
    }
  }
  return true;
}

const crypto = require('crypto');


// case1: long random string
const str1 = crypto.randomBytes(10000).toString('hex');
const str2 = crypto.randomBytes(10000).toString('hex');

console.log(checkPermutation(str1, str1));
console.log(checkPermutation1(str1, str1));
console.log(checkPermutation2(str1, str1));

// measure performance
console.time('checkPermutation');
for (let i = 0; i < 1000; i++) {
  checkPermutation(str1, str2);
}
console.timeEnd('checkPermutation');

console.time('checkPermutation1');
for (let i = 0; i < 1000; i++) {
  checkPermutation1(str1, str2);
}
console.timeEnd('checkPermutation1');

console.time('checkPermutation2');
for (let i = 0; i < 1000; i++) {
  checkPermutation2(str1, str2);
}
console.timeEnd('checkPermutation2');

// case2 short random string
const str3 = crypto.randomBytes(10).toString('hex');
const str4 = crypto.randomBytes(10).toString('hex');

console.log(checkPermutation(str3, str3));
console.log(checkPermutation1(str3, str3));
console.log(checkPermutation2(str3, str3));

// measure performance
console.time('checkPermutation');
for (let i = 0; i < 1000000; i++) {
  checkPermutation(str3, str4);
}
console.timeEnd('checkPermutation');

console.time('checkPermutation1');
for (let i = 0; i < 1000000; i++) {
  checkPermutation1(str3, str4);
}
console.timeEnd('checkPermutation1');

console.time('checkPermutation2');
for (let i = 0; i < 1000000; i++) {
  checkPermutation2(str3, str4);
}
console.timeEnd('checkPermutation2');

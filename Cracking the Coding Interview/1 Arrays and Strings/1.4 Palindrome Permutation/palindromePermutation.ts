// Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palin- drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
// Input: Tact Coa
// Output: True (permutations: "taco cat", "atco cta", etc.)
import * as crypto from 'crypto';

const isPalindromePermutation = (str: string): boolean => {
  const strArray = str.toLowerCase().split('');
  const stringMap: { [key: string]: number } = {};
  strArray.forEach((char: string) => {
    if (char === ' ') return;
    stringMap[char] = stringMap[char] ? stringMap[char] + 1 : 1;
  });

  let oddCount = 0;
  for (const value of Object.values(stringMap)) {
    if (value % 2 === 1) {
      oddCount += 1;
    }
    if (oddCount >= 2) {
      return false;
    }
  }
  return true;
};

const isPalindromePermutation2 = (str: string): boolean => {
  const charMap = new Map<string, number>();
  let oddCount = 0;
  for (let i = 0; i < str.length; i++) {
    const char = str[i].toLowerCase();
    if (char === ' ') continue;
    if (charMap.has(char)) {
      charMap.set(char, charMap.get(char)! + 1);
    } else {
      charMap.set(char, 1);
    }
  }
  for (const value of charMap.values()) {
    if (value % 2 !== 0) oddCount++;
  }
  return oddCount <= 1;
};

// measure performance
const str = crypto.randomBytes(10000).toString('hex');
console.log(isPalindromePermutation('Tact Coa'));
console.log(isPalindromePermutation(str));
console.time('isPalindromePermutation');
for (let index = 0; index < 1000; index++) {
  isPalindromePermutation('Tact Coa');
  isPalindromePermutation(str);
}
console.timeEnd('isPalindromePermutation');

console.log(isPalindromePermutation2('Tact Coa'));
console.log(isPalindromePermutation2(str));
console.time('isPalindromePermutation2');
for (let index = 0; index < 1000; index++) {
  isPalindromePermutation2('Tact Coa');
  isPalindromePermutation2(str);
}
console.timeEnd('isPalindromePermutation2');

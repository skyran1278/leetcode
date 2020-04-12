/* eslint-disable no-unused-vars */
/**
 * @param {string} digits
 * @return {string[]}
 */
const letterCombinations = (digits) => {
  if (!digits) return [];

  const map = {
    2: ['a', 'b', 'c'],
    3: ['d', 'e', 'f'],
    4: ['g', 'h', 'i'],
    5: ['j', 'k', 'l'],
    6: ['m', 'n', 'o'],
    7: ['p', 'q', 'r', 's'],
    8: ['t', 'u', 'v'],
    9: ['w', 'x', 'y', 'z'],
  };

  let letters = map[digits[0]];
  [...digits.substring(1)].forEach((number) => {
    const t = [];
    map[number].forEach((letter2) => {
      letters.forEach((letter1) => t.push(letter1 + letter2));
    });
    letters = t;
  });
  return letters;
};

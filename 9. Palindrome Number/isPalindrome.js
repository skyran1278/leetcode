/**
 * @param {number} x
 * @return {boolean}
 */
const isPalindrome = (x) => {
  if (x < 0) return false;
  const s = x.toString(10);
  return s.split('').reverse().join('') === s;
};

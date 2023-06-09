/**
 * to String solution
 * @param {number} x
 * @return {boolean}
 */
// const isPalindrome = (x) => {
//   if (x < 0) return false;
//   const s = x.toString(10);
//   return s.split('').reverse().join('') === s;
// };

/**
 * avoid toString solution
 * @param {number} x
 * @return {boolean}
 */
// const isPalindrome = (x) => {
//   if (x < 0) return false;
//   if (x < 10) return true;
//   let y = x;
//   const number = [];
//   while (y >= 10) {
//     number.push(y % 10);
//     y = Math.floor(y / 10);
//   }
//   number.push(y % 10);
//   return parseInt(number.join(''), 10) === x;
// };

/**
 * best speed solution
 * @param {number} x
 * @return {boolean}
 */
const isPalindrome = (x) => {
  if (x < 0) return false;

  let rev = 0;

  let i = x;
  while (i > 0) {
    rev = rev * 10 + (i % 10);
    i = Math.floor(i / 10);
  }
  return rev === x;
};

isPalindrome(1001);

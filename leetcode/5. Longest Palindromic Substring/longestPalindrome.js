/**
 * 時間複雜度太大
 * @param {string} s
 * @return {string}
 */
// const longestPalindrome = (s) => {
//   let max = -1;
//   let end = 0;
//   let start = 0;
//   const x = s.split('');
//   for (let i = 0; i < x.length; i += 1) {
//     for (let j = 0; j < x.length; j += 1) {
//       if (x[i] === x[j]) {
//         let left = i + 1;
//         let right = j - 1;
//         while (x[left] === x[right] && left + 1 < right) {
//           left += 1;
//           right -= 1;
//         }
//         if (left + 1 >= right && x[left] === x[right] && j - i + 1 > max) {
//           max = j - i + 1;
//           start = i;
//           end = j;
//         }
//       }
//     }
//   }
//   return s.substring(start, end + 1);
// };

/**
 * @param {string} s
 * @return {string}
 */
const longestPalindrome = (s) => {
  let max = '';
  for (let i = 0; i < s.length; i += 1) {
    // 兩種對稱性
    for (let j = 0; j < 2; j += 1) {
      let left = i;
      let right = i + j;
      while (s[left] && s[left] === s[right]) {
        left -= 1;
        right += 1;
      }
      // 多加一次的修正
      if (right - left - 1 > max.length) {
        max = s.substring(left + 1, right);
      }
    }
  }
  return max;
};

// console.log(longestPalindrome('babad'));
// console.log(longestPalindrome('cbbd'));
// console.log(longestPalindrome('bb'));
console.log(longestPalindrome('a'));
// console.log(longestPalindrome('ac'));
// console.log(longestPalindrome('ccc'));
// console.log(longestPalindrome('abcba'));
// console.log(longestPalindrome('aaabaaaa'));

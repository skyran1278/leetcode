/**
 * @param {string[]} strs
 * @return {string}
 */
const longestCommonPrefix = (strs) =>
  strs.reduce((prev, next) => {
    let i = 0;
    while (prev[i] && prev[i] === next[i]) {
      i += 1;
    }
    return prev.substring(0, i);
  }, strs[0] || '');

console.log(longestCommonPrefix(['flower', 'flow', 'flight']));
console.log(longestCommonPrefix([]));

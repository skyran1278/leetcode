/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
const isMatch = (s, p) => {
  if (s === p) return true;

  const firstMatch = s[0] !== undefined && (p[0] === s[0] || p.startsWith('.'));

  if (p.length >= 2 && p[1] === '*') {
    return (
      isMatch(s, p.substring(2, p.length)) ||
      (firstMatch && isMatch(s.substring(1, s.length), p))
    );
  }

  return (
    firstMatch && isMatch(s.substring(1, s.length), p.substring(1, p.length))
  );
};

/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
const isMatchDpTopDown = (s, p) => {
  const memo = {};

  const dp = (str, pattern) => {
    if (memo[`${str},${pattern}`] !== undefined) {
      return memo[`${str},${pattern}`];
    }

    if (str === pattern) return true;

    const firstMatch =
      str[0] !== undefined && (pattern[0] === str[0] || pattern[0] === '.');

    if (pattern.length >= 2 && pattern[1] === '*') {
      memo[`${str},${pattern}`] =
        dp(str, pattern.substring(2, pattern.length)) ||
        (firstMatch && dp(str.substring(1, str.length), pattern));
    } else {
      memo[`${str},${pattern}`] =
        firstMatch &&
        dp(str.substring(1, str.length), pattern.substring(1, pattern.length));
    }

    return memo[`${str},${pattern}`];
  };

  return dp(s, p);
};

console.log(!isMatch('aa', 'a'));
console.log(isMatch('aa', 'a*'));
console.log(isMatch('aa', 'b*aa'));
console.log(isMatch('ab', '.*'));
console.log(isMatch('aaa', 'a*a'));

/**
 * ERROR: still error
 */

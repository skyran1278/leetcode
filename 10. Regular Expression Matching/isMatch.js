/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
const isMatch = (s, p) => {
  if (s === p) return true;

  const firstMatch = s[0] !== undefined && (p[0] === s[0] || p[0] === '.');

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

console.log(isMatch('aa', 'a'));
console.log(isMatch('aa', 'a*'));
console.log(isMatch('aa', 'b*aa'));
console.log(isMatch('ab', '.*'));
console.log(isMatch('aaa', 'a*a'));

/**
 * ERROR: still error
 */

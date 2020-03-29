/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
const isMatch = (s, p) => {
  if (s === p) return true;
  const firstMatch = p[0] in [s[0], '.'];
  if (p.length >= 2 && p[1] === '*') {
    return firstMatch ? isMatch(s.substring(1, s.length), p) : isMatch(s, p(2, p.length));
  }
  return firstMatch && isMatch(s.substring(1, s.length), p.substring(1, p.length));
};

/**
 * ERROR: still error
 */

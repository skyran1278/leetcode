/**
 * @param {string} str
 * @return {number}
 */
const myAtoi = (str) => {
  const x = parseInt(str, 10);
  if (x > 0x7fffffff) {
    return 2147483647;
  }
  if (x < -0x80000000) {
    return -2147483648;
  }
  if (isNaN(x)) {
    return 0;
  }
  return x;
};

/**
 * @param {string} str
 * @return {number}
 */
const myAtoi = (str) => (Math.min(Math.max(parseInt(str, 10) || 0, -0x80000000), 0x7fffffff));

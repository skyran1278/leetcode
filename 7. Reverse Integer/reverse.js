/**
 * @param {number} x
 * @return {number}
 */
const reverse = (x) => {
  const reversed = parseInt(Math.abs(x).toString().split('').reverse()
    .join(''), 10) * Math.sign(x);
  // 2147483647 -2147483648
  return (reversed > 0x7fffffff || reversed < -0x80000000) ? 0 : reversed;
};

console.log(reverse(1534236469));

/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
const convert = (s, numRows) => {
  // return original string if can't zigzag
  if (numRows === 1 || s.length < numRows) return s;

  const x = Array(numRows).fill(null).map(() => ([]));
  let row = 0;
  let positive = false;
  for (let i = 0; i < s.length; i += 1) {
    x[row].push(s[i]);
    positive = i % (numRows - 1) === 0 ? !positive : positive;
    row = positive ? row + 1 : row - 1;
  }
  return x.map((v) => v.join('')).join('');
};

// console.log(convert('PAYPALISHIRING', 3));
console.log(convert('AB', 1));

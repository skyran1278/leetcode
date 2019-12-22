/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
const convert = (s, numRows) => {
  const x = Array(numRows).fill(null).map(() => ([]));
  let row = 0;
  let i = 0;
  let positive = 0;
  x[row].push(s[i]);
  while (i < s.length) {
    positive += 1;
    for (let j = 0; j < numRows - 1; j += 1) {
      i += 1;
      row = positive % 2 === 1 ? row + 1 : row - 1;
      x[row].push(s[i]);
    }
  }
  return x.map((v) => v.join('')).join('');
};

console.log(convert('PAYPALISHIRING', 3));

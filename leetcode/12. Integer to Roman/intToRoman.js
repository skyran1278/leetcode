/**
 * @param {number} num
 * @return {string}
 */
const intToRoman = (num) => {
  const romanInt = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
  const roman = [
    'M',
    'CM',
    'D',
    'CD',
    'C',
    'XC',
    'L',
    'XL',
    'X',
    'IX',
    'V',
    'IV',
    'I',
  ];

  let n = num;
  let i = 0;
  let s = '';
  while (n > 0) {
    if (n - romanInt[i] >= 0) {
      n -= romanInt[i];
      s += roman[i];
    } else {
      i += 1;
    }
  }
  return s;
};

console.log(intToRoman(3));

// /**
//  * @param {number} n
//  * @return {string[]}
//  */
// const generateParenthesis = (n) => {
//   let x = ['('];
//   while (x[0].length < 2 * n) {
//     const t = [];
//     x.forEach((e) => {
//       const v = e.split('').reduce((prev, next) => {
//         prev += next === '(' ? 1 : -1;
//         return prev;
//       }, 0);
//       const v2 = e.split('').reduce((prev, next) => {
//         prev += next === '(' ? 1 : -1;
//         return prev;
//       }, 0);
//       if (v > 0) {
//         t.push(`${i})`);
//       }
//       if (v < n && v2 < n) {
//         t.push(`${i}(`);
//       }
//     });
//     x = t;
//   }
//   return x;
// };

/**
 * @param {number} n
 * @return {string[]}
 */
const generateParenthesis = (n) => {
  const result = [];

  const canInsertRightParentheses = (track) => {
    const leftParenthesesCount = (track.match(/\(/g) || []).length;
    const rightParenthesesCount = (track.match(/\)/g) || []).length;
    return rightParenthesesCount < leftParenthesesCount;
  };

  const isValid = (track) => {
    const leftParenthesesCount = (track.match(/\(/g) || []).length;
    const rightParenthesesCount = (track.match(/\)/g) || []).length;
    return rightParenthesesCount === leftParenthesesCount;
  };

  const backtrace = (track, rest) => {
    if (rest.length === 0) {
      result.push(track);
    }

    rest.forEach((parentheses) => {});

    if (canInsertRightParentheses(track)) {
    }
  };

  backtrace('', Array(n).fill('(').concat(Array(n).fill(')')));
};

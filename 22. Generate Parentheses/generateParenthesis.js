/**
 * has error
 * @param {number} n
 * @return {string[]}
 */
const generateParenthesis = (n) => {
  let x = ['('];
  while (x[0].length < 2 * n) {
    const t = [];
    x.forEach((e) => {
      const v = e.split('').reduce((prev, next) => {
        prev += next === '(' ? 1 : -1;
        return prev;
      }, 0);
      const v2 = e.split('').reduce((prev, next) => {
        prev += next === '(' ? 1 : -1;
        return prev;
      }, 0);
      if (v > 0) {
        t.push(`${e})`);
      }
      if (v < n && v2 < n) {
        t.push(`${e}(`);
      }
    });
    x = t;
  }
  return x;
};

/**
 * @param {number} n
 * @return {string[]}
 */
const generateParenthesisV2 = (n) => {
  const result = new Set();

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
      result.add(track);
    }

    for (let index = 0; index < rest.length; index += 1) {
      const parentheses = rest[index];

      if (!canInsertRightParentheses(track) && parentheses === ')') {
        // eslint-disable-next-line no-continue
        continue;
      }

      const newRest = [...rest];
      newRest.splice(index, 1);

      backtrace(track + parentheses, newRest);
    }
  };

  backtrace('', Array(n).fill('(').concat(Array(n).fill(')')));

  return Array.from(result);
};

/**
 * @param {number} n
 * @return {string[]}
 */
const generateParenthesisV3 = (n) => {
  const result = [];

  const backtrace = (track, leftRest, rightRest) => {
    if (leftRest === 0 && rightRest === 0) {
      result.push(track);
    }

    if (leftRest > 0) {
      backtrace(`${track}(`, leftRest - 1, rightRest);
    }

    if (rightRest > leftRest) {
      backtrace(`${track})`, leftRest, rightRest - 1);
    }
  };

  backtrace('', n, n);

  return result;
};

console.log(generateParenthesis(3));

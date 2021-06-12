/**
 * @param {string} s
 * @return {boolean}
 */
const isValid = (s) => {
  const stack = [];

  if (s.length === 0) {
    return true;
  }

  if (s.length % 2 === 1) {
    return false;
  }

  for (let i = 0; i < s.length; i += 1) {
    const parentheses = s[i];
    if (parentheses === '(' || parentheses === '[' || parentheses === '{') {
      stack.push(parentheses);
    } else {
      const leftParentheses = stack.pop();
      switch (parentheses) {
        // case '(':
        // case '[':
        // case '{':
        //   stack.push(parentheses);
        //   break;
        case ')':
          if (leftParentheses !== '(') {
            return false;
          }
          break;
        case ']':
          if (leftParentheses !== '[') {
            return false;
          }
          break;
        case '}':
          if (leftParentheses !== '{') {
            return false;
          }
          break;
        default:
          return false;
      }
    }
  }

  return stack.length === 0;
};

console.log(isValid('()'));
console.log(isValid('()[]{}'));

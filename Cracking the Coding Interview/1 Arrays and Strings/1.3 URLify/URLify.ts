// URLify: Write a method to replace all spaces in a string with '%20'.
// You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.
// (Note: If implementing in Java, please use a character array so that you can perform this operation in place.)
// EXAMPLE
// Input: "Mr John Smith     ", 13
// Output: "Mr%203ohn%20Smith"
export const URLify = (str: string | string[], len: number) => {
  let newStr = '';

  for (let i = 0; i < len; i++) {
    if (str[i] === ' ') {
      newStr += '%20';
    } else {
      newStr += str[i];
    }
  }

  return newStr;
};

// eslint-disable-next-line @typescript-eslint/no-unused-vars
export const URLify2 = (str: string, _len: number) => {
  return str.trim().replace(/ /g, '%20');
};

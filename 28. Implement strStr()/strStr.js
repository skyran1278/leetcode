/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
const strStr = (haystack, needle) => {
  if (needle === '') {
    return 0;
  }
  for (let i = 0; i < haystack.length; i += 1) {
    if (
      haystack[i] === needle[0] &&
      haystack.slice(i, i + needle.length) === needle
    ) {
      return i;
    }
  }
  return -1;
};

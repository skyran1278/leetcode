// Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.
export const checkPermutation = (str1: string, str2: string) => {
  if (str1.length !== str2.length) return false;
  const str1Arr = str1.split('');
  const str2Arr = str2.split('');
  const str1Obj: { [key: string]: number } = {};
  const str2Obj: { [key: string]: number } = {};
  str1Arr.forEach((char: string | number) => {
    str1Obj[char] = str1Obj[char] + 1 || 1;
  });
  str2Arr.forEach((char: string | number) => {
    str2Obj[char] = str2Obj[char] + 1 || 1;
  });
  for (const key in str1Obj) {
    if (str1Obj[key] !== str2Obj[key]) return false;
  }
  return true;
};

// Solution #1: Sort the strings.
// Time Complexity: O(n log n)
// Space Complexity: O(1)
export const checkPermutation1 = (str1: string, str2: string) => {
  if (str1.length !== str2.length) return false;
  return str1.split('').sort().join('') === str2.split('').sort().join('');
};

// 建一個表，看看他有沒有用完
// Solution #2: Check if the two strings have identical character counts.
// Time Complexity: O(n)
// Space Complexity: O(n)
export const checkPermutation2 = (str1: string, str2: string) => {
  if (str1.length !== str2.length) return false;
  const charCount: { [key: string]: number } = {};
  for (let i = 0; i < str1.length; i++) {
    if (charCount[str1[i]]) {
      charCount[str1[i]]++;
    } else {
      charCount[str1[i]] = 1;
    }
  }
  for (let i = 0; i < str2.length; i++) {
    if (charCount[str2[i]]) {
      charCount[str2[i]]--;
    } else {
      return false;
    }
  }
  return true;
};

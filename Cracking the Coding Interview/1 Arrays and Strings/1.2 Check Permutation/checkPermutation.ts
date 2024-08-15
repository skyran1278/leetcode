// Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

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

  const charCount: Record<string, number> = {};

  for (const char of str1) {
    charCount[char] = (charCount[char] ?? 0) + 1;
  }

  for (const char of str2) {
    if (charCount[char]) {
      charCount[char]--;
    } else {
      return false;
    }
  }

  return true;
};

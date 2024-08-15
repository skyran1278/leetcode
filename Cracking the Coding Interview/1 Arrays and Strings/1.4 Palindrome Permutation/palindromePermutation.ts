// Palindrome Permutation:
// Given a string, write a function to check if it is a permutation of a palindrome.
// A palindrome is a word or phrase that is the same forwards and backwards.
// A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
// Input: Tact Coa
// Output: True (permutations: "taco cat", "atco cta", etc.)
export const isPalindromePermutation2 = (str: string): boolean => {
  const charMap = new Map<string, number>();

  let oddCount = 0;
  for (const char of str.toLowerCase()) {
    if (char === ' ') continue;
    charMap.set(char, (charMap.get(char) ?? 0) + 1);
  }

  for (const value of charMap.values()) {
    if (value % 2 !== 0) oddCount++;
  }

  return oddCount <= 1;
};

// Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palin- drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
// Input: Tact Coa
// Output: True (permutations: "taco cat", "atco cta", etc.)
export const isPalindromePermutation = (str: string): boolean => {
  const strArray = str.toLowerCase().split('');
  const stringMap: Record<string, number> = {};
  strArray.forEach((char: string) => {
    if (char === ' ') return;
    stringMap[char] = stringMap[char] ? stringMap[char] + 1 : 1;
  });

  let oddCount = 0;
  for (const value of Object.values(stringMap)) {
    if (value % 2 === 1) {
      oddCount += 1;
    }
    if (oddCount >= 2) {
      return false;
    }
  }
  return true;
};

export const isPalindromePermutation2 = (str: string): boolean => {
  const charMap = new Map<string, number>();
  let oddCount = 0;
  for (const upperChar of str) {
    const char = upperChar.toLowerCase();
    if (char === ' ') continue;
    if (charMap.has(char)) {
      charMap.set(char, charMap.get(char)! + 1);
    } else {
      charMap.set(char, 1);
    }
  }
  for (const value of charMap.values()) {
    if (value % 2 !== 0) oddCount++;
  }
  return oddCount <= 1;
};

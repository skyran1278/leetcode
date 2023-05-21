// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

export const isUnique = (str: string) => {
  const strArr = str.split('');
  let unique = true;
  strArr.forEach((char: string, index: number) => {
    if (strArr.indexOf(char) !== index) {
      unique = false;
    }
  });
  return unique;
};

// 1. key-value pair O(1)
// 2. create all characters array O(1)
// if can't use additional data structures
// 1. for loop in-place O(n^2)
// 2. sort the string O(n log n) + for loop O(n)

// if is ascii, there is only 256 character, then I can use an array to store the character and check if it is already in the array
// O(n) time complexity
// if is unicode
// if cannot use additional data structures, only can compare each character with the rest of the string
// O(n^2) time complexity

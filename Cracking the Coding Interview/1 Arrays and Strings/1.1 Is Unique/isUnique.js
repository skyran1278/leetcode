// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

const isUnique = (str) => {
  let strArr = str.split('');
  let unique = true;
  strArr.forEach((char, index) => {
    if (strArr.indexOf(char) !== index) {
      unique = false;
    }
  });
  return unique;
}

// if is ascii, there is only 256 character, then I can use an array to store the character and check if it is already in the array
// O(n) time complexity
// if is unicode
// if cannot use additional data structures, only can compare each character with the rest of the string
// O(n^2) time complexity

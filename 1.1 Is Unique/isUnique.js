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

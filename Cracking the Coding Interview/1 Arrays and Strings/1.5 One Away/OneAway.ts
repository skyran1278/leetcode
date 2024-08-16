// One Away: There are three types of edits that can be performed on strings:
// insert a character, remove a character, or replace a character.
// Given two strings, write a function to check if they are one edit (or zero edits) away.
// EXAMPLE
// pale, ple -> true
// pales, pale -> true
// pale, bale -> true
// pale, bake -> false

const oneEditReplace = (str1: string, str2: string): boolean => {
  let foundDifference = false;
  for (let i = 0; i < str1.length; i++) {
    if (str1[i] !== str2[i]) {
      if (foundDifference) {
        return false;
      }
      foundDifference = true;
    }
  }
  return true;
};

const oneEditInsert = (str1: string, str2: string): boolean => {
  let index1 = 0;
  let index2 = 0;
  while (index2 < str2.length && index1 < str1.length) {
    if (str1[index1] !== str2[index2]) {
      if (index1 !== index2) {
        return false;
      }
      index2++;
    } else {
      index1++;
      index2++;
    }
  }
  return true;
};

export const oneAway2 = (str1: string, str2: string): boolean => {
  if (str1.length === str2.length) {
    return oneEditReplace(str1, str2);
  } else if (str1.length + 1 === str2.length) {
    return oneEditInsert(str1, str2);
  } else if (str1.length - 1 === str2.length) {
    return oneEditInsert(str2, str1);
  }
  return false;
};

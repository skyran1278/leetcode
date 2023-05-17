// One Away: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.
// EXAMPLE
// pale, ple -> true
// pales, pale -> true
// pale, bale -> true
// pale, bake -> false

enum PerformedType {
  Insert,
  Remove,
  Replace,
  Undefined,
}

export const oneAway = (str1: string, str2: string): boolean => {
  if (Math.abs(str1.length - str2.length) > 1) {
    return false;
  }

  const longerStr = str1.length > str2.length ? str1 : str2;
  const shorterStr = str1.length > str2.length ? str2 : str1;

  const performedType =
    longerStr.length === shorterStr.length
      ? PerformedType.Replace
      : PerformedType.Insert;

  let differentCount = 0;
  if (performedType === PerformedType.Insert) {
    for (
      let str1Index = 0, str2Index = 0;
      str1Index < longerStr.length;
      str1Index++
    ) {
      if (differentCount === 2) {
        return false;
      }
      const char1 = longerStr[str1Index];
      const char2 = shorterStr[str2Index];
      if (char1 !== char2) {
        differentCount += 1;
        continue;
      }
      str2Index++;
    }
  }
  if (performedType === PerformedType.Replace) {
    for (let index = 0; index < str1.length; index++) {
      if (differentCount === 2) {
        return false;
      }
      const char1 = str1[index];
      const char2 = str2[index];
      if (char1 !== char2) {
        differentCount += 1;
      }
    }
  }
  return true;
};

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

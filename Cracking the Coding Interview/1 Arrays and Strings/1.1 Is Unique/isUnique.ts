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

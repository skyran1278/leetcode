// String Compression: Implement a method to perform basic string compression using the counts of repeated characters.
// For example, the string aabcccccaaa would become a2b1c5a3,
// If the "compressed" string would not become smaller than the original string, your method should return the original string.
// You can assume the string has only uppercase and lowercase letters (a - z).

export const stringCompression = (str: string) => {
  let compressed = '';
  let count = 0;
  for (let i = 0; i < str.length; i++) {
    count++;
    if (i + 1 >= str.length || str[i] !== str[i + 1]) {
      compressed += `${str[i]}${count}`;
      count = 0;
    }
  }
  return compressed.length < str.length ? compressed : str;
};

// optimized by preallocating the string length
// 沒有比較好，因為 js 無法預先分配記憶體空間，所以這樣反而會比較慢
export const stringCompression2 = (str: string) => {
  const compressedLength = getCompressedLength(str);
  if (compressedLength >= str.length) return str;
  const compressed = new Array(compressedLength);
  let count = 0;
  for (let i = 0, j = 0; i < str.length; i++, j++) {
    count++;
    if (i + 1 >= str.length || str[i] !== str[i + 1]) {
      compressed[j] = str[i];
      for (const char of count.toString()) {
        compressed[++j] = char;
      }
      count = 0;
    }
  }
  return compressed.join('');
};

const getCompressedLength = (str: string) => {
  let compressedLength = 0;
  let count = 0;
  for (let i = 0; i < str.length; i++) {
    count++;
    if (i + 1 >= str.length || str[i] !== str[i + 1]) {
      compressedLength += 1 + count.toString().length;
      count = 0;
    }
  }
  return compressedLength;
};

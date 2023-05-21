import {
  checkPermutation,
  checkPermutation1,
  checkPermutation2,
} from './checkPermutation'; // Replace 'your-module' with the actual module path

describe('checkPermutation', () => {
  it('should return true if one string is a permutation of the other', () => {
    const str1 = 'abcd';
    const str2 = 'dcba';
    const result = checkPermutation(str1, str2);
    expect(result).toBe(true);
  });

  it('should return false if the lengths of the strings are different', () => {
    const str1 = 'abc';
    const str2 = 'abcd';
    const result = checkPermutation(str1, str2);
    expect(result).toBe(false);
  });

  it('should return false if one string is not a permutation of the other', () => {
    const str1 = 'abcd';
    const str2 = 'abce';
    const result = checkPermutation(str1, str2);
    expect(result).toBe(false);
  });
});

describe('checkPermutation1', () => {
  it('should return true if one string is a permutation of the other', () => {
    const str1 = 'abcd';
    const str2 = 'dcba';
    const result = checkPermutation1(str1, str2);
    expect(result).toBe(true);
  });

  it('should return false if the lengths of the strings are different', () => {
    const str1 = 'abc';
    const str2 = 'abcd';
    const result = checkPermutation1(str1, str2);
    expect(result).toBe(false);
  });

  it('should return false if one string is not a permutation of the other', () => {
    const str1 = 'abcd';
    const str2 = 'abce';
    const result = checkPermutation1(str1, str2);
    expect(result).toBe(false);
  });
});

describe('checkPermutation2', () => {
  it('should return true if one string is a permutation of the other', () => {
    const str1 = 'abcd';
    const str2 = 'dcba';
    const result = checkPermutation2(str1, str2);
    expect(result).toBe(true);
  });

  it('should return false if the lengths of the strings are different', () => {
    const str1 = 'abc';
    const str2 = 'abcd';
    const result = checkPermutation2(str1, str2);
    expect(result).toBe(false);
  });

  it('should return false if one string is not a permutation of the other', () => {
    const str1 = 'abcd';
    const str2 = 'abce';
    const result = checkPermutation2(str1, str2);
    expect(result).toBe(false);
  });
});

describe('Performance comparison', () => {
  it('should compare the performance of checkPermutation, checkPermutation1, and checkPermutation2', () => {
    const longStr1 = 'a'.repeat(500000) + 'b';
    const longStr2 = 'b'.repeat(500000) + 'a';

    console.time('checkPermutation');
    checkPermutation(longStr1, longStr2);
    console.timeEnd('checkPermutation');

    console.time('checkPermutation1');
    checkPermutation1(longStr1, longStr2);
    console.timeEnd('checkPermutation1');

    console.time('checkPermutation2');
    checkPermutation2(longStr1, longStr2);
    console.timeEnd('checkPermutation2');
  });
});

import { checkPermutation1, checkPermutation2 } from './checkPermutation'; // Replace 'your-module' with the actual module path

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

    const startTime2 = process.hrtime();
    checkPermutation1(longStr1, longStr2);
    const endTime2 = process.hrtime(startTime2);
    const executionTime2 = endTime2[0] * 1000 + endTime2[1] / 1000000; // Convert to milliseconds

    const startTime3 = process.hrtime();
    checkPermutation2(longStr1, longStr2);
    const endTime3 = process.hrtime(startTime3);
    const executionTime3 = endTime3[0] * 1000 + endTime3[1] / 1000000; // Convert to milliseconds

    expect(executionTime3).toBeLessThan(executionTime2);
    // expect(executionTime1).toBeLessThan(executionTime2);
  });
});

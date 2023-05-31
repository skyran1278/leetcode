import { stringCompression, stringCompression2 } from './stringCompression'; // Replace 'your-module' with the actual module path

describe('stringCompression', () => {
  it('should compress the string correctly', () => {
    const str = 'aabcccccaaa';
    const expected = 'a2b1c5a3';

    const result = stringCompression(str);
    expect(result).toEqual(expected);
  });

  it('should return the original string if compressed string is not smaller', () => {
    const str = 'abcde';
    const expected = 'abcde';

    const result = stringCompression(str);
    expect(result).toEqual(expected);
  });

  it('should handle an empty string', () => {
    const str = '';
    const expected = '';

    const result = stringCompression(str);
    expect(result).toEqual(expected);
  });
});

describe('stringCompression2', () => {
  it('should compress the string correctly', () => {
    const str = 'aabcccccaaa';
    const expected = 'a2b1c5a3';

    const result = stringCompression2(str);
    expect(result).toEqual(expected);
  });

  it('should return the original string if compressed string is not smaller', () => {
    const str = 'abcde';
    const expected = 'abcde';

    const result = stringCompression2(str);
    expect(result).toEqual(expected);
  });

  it('should handle an empty string', () => {
    const str = '';
    const expected = '';

    const result = stringCompression2(str);
    expect(result).toEqual(expected);
  });
});

describe('Performance comparison', () => {
  it('stringCompression should better than stringCompression2', () => {
    const longStr = 'a'.repeat(1000000);

    const startTime1 = process.hrtime();
    stringCompression(longStr);
    const endTime1 = process.hrtime(startTime1);
    const executionTime1 = endTime1[0] * 1000 + endTime1[1] / 1000000; // Convert to milliseconds

    const startTime2 = process.hrtime();
    stringCompression2(longStr);
    const endTime2 = process.hrtime(startTime2);
    const executionTime2 = endTime2[0] * 1000 + endTime2[1] / 1000000; // Convert to milliseconds

    expect(executionTime1).toBeLessThanOrEqual(executionTime2);
  });
});

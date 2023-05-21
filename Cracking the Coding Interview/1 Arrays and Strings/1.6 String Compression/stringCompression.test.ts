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
  it('should compare the performance of stringCompression and stringCompression2', () => {
    const longStr = 'a'.repeat(1000000);

    console.time('stringCompression');
    stringCompression(longStr);
    console.timeEnd('stringCompression');

    console.time('stringCompression2');
    stringCompression2(longStr);
    console.timeEnd('stringCompression2');
  });
});

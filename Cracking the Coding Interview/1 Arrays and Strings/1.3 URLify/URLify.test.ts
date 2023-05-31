import { URLify, URLify2 } from './URLify'; // Replace 'your-module' with the actual module path

describe('URLify', () => {
  it('should replace spaces in the string with "%20"', () => {
    const str = 'Mr John Smith     ';
    const len = 13;
    const expected = 'Mr%20John%20Smith';

    const result = URLify(str, len);
    expect(result).toEqual(expected);
  });

  it('should handle a string without spaces', () => {
    const str = 'HelloWorld';
    const len = 10;
    const expected = 'HelloWorld';

    const result = URLify(str, len);
    expect(result).toEqual(expected);
  });

  it('should handle an empty string', () => {
    const str = '';
    const len = 0;
    const expected = '';

    const result = URLify(str, len);
    expect(result).toEqual(expected);
  });
});

describe('URLify2', () => {
  it('should replace spaces in the string with "%20"', () => {
    const str = 'Mr John Smith     ';
    const len = 13;
    const expected = 'Mr%20John%20Smith';

    const result = URLify2(str, len);
    expect(result).toEqual(expected);
  });

  it('should handle a string without spaces', () => {
    const str = 'HelloWorld';
    const len = 10;
    const expected = 'HelloWorld';

    const result = URLify2(str, len);
    expect(result).toEqual(expected);
  });

  it('should handle an empty string', () => {
    const str = '';
    const len = 0;
    const expected = '';

    const result = URLify2(str, len);
    expect(result).toEqual(expected);
  });
});

describe('Performance comparison', () => {
  it('URLify2 should almost same as URLify"', () => {
    const longStr = 'a '.repeat(500000) + 'b';
    const len = longStr.length;

    const startTime1 = process.hrtime();
    URLify(longStr, len);
    const endTime1 = process.hrtime(startTime1);
    const executionTime1 = endTime1[0] * 1000 + endTime1[1] / 1000000; // Convert to milliseconds

    const startTime2 = process.hrtime();
    URLify2(longStr, len);
    const endTime2 = process.hrtime(startTime2);
    const executionTime2 = endTime2[0] * 1000 + endTime2[1] / 1000000; // Convert to milliseconds

    const acceptableExecutionTime = 100; // Specify the acceptable execution time in milliseconds
    expect(executionTime1).toBeLessThan(acceptableExecutionTime);
    expect(executionTime2).toBeLessThan(acceptableExecutionTime);
  });
});

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
  it('should compare the performance of URLify and URLify2', () => {
    const longStr = 'a '.repeat(500000) + 'b';
    const len = longStr.length;

    console.time('URLify');
    URLify(longStr, len);
    console.timeEnd('URLify');

    console.time('URLify2');
    URLify2(longStr, len);
    console.timeEnd('URLify2');
  });
});

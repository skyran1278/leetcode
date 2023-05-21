import { isUnique } from './isUnique'; // Replace 'your-module' with the actual module path

describe('isUnique', () => {
  it('should return true for a string with all unique characters', () => {
    const str = 'abcdefg';
    const result = isUnique(str);
    expect(result).toBe(true);
  });

  it('should return false for a string with duplicate characters', () => {
    const str = 'hello';
    const result = isUnique(str);
    expect(result).toBe(false);
  });
});

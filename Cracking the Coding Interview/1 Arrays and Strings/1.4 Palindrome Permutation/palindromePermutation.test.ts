import { isPalindromePermutation2 } from './palindromePermutation';

describe('isPalindromePermutation', () => {
  it('returns true for a valid palindrome permutation', () => {
    const input = 'Tact Coa';
    const expectedOutput = true;

    expect(isPalindromePermutation2(input)).toBe(expectedOutput);
  });

  it('returns true for a valid palindrome permutation with special characters', () => {
    const input = 'Able , Elba';
    const expectedOutput = true;

    expect(isPalindromePermutation2(input)).toBe(expectedOutput);
  });

  it('returns false for an invalid palindrome permutation', () => {
    const input = 'Hello World';
    const expectedOutput = false;

    expect(isPalindromePermutation2(input)).toBe(expectedOutput);
  });

  it('returns true for an empty string', () => {
    const input = '';
    const expectedOutput = true;

    expect(isPalindromePermutation2(input)).toBe(expectedOutput);
  });

  it('returns true for a string with only spaces', () => {
    const input = '      ';
    const expectedOutput = true;

    expect(isPalindromePermutation2(input)).toBe(expectedOutput);
  });

  it('returns true for a string with only one character', () => {
    const input = 'a';
    const expectedOutput = true;

    expect(isPalindromePermutation2(input)).toBe(expectedOutput);
  });
});

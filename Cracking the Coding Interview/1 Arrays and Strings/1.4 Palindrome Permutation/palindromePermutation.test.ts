import {
  isPalindromePermutation,
  isPalindromePermutation2,
} from './palindromePermutation';

describe('isPalindromePermutation', () => {
  it('returns true for a valid palindrome permutation', () => {
    const input = 'Tact Coa';
    const expectedOutput = true;

    expect(isPalindromePermutation(input)).toBe(expectedOutput);
    expect(isPalindromePermutation2(input)).toBe(expectedOutput);
  });

  it('returns true for a valid palindrome permutation with special characters', () => {
    const input = 'Able , Elba';
    const expectedOutput = true;

    expect(isPalindromePermutation(input)).toBe(expectedOutput);
    expect(isPalindromePermutation2(input)).toBe(expectedOutput);
  });

  it('returns false for an invalid palindrome permutation', () => {
    const input = 'Hello World';
    const expectedOutput = false;

    expect(isPalindromePermutation(input)).toBe(expectedOutput);
    expect(isPalindromePermutation2(input)).toBe(expectedOutput);
  });

  it('returns true for an empty string', () => {
    const input = '';
    const expectedOutput = true;

    expect(isPalindromePermutation(input)).toBe(expectedOutput);
    expect(isPalindromePermutation2(input)).toBe(expectedOutput);
  });

  it('returns true for a string with only spaces', () => {
    const input = '      ';
    const expectedOutput = true;

    expect(isPalindromePermutation(input)).toBe(expectedOutput);
    expect(isPalindromePermutation2(input)).toBe(expectedOutput);
  });

  it('returns true for a string with only one character', () => {
    const input = 'a';
    const expectedOutput = true;

    expect(isPalindromePermutation(input)).toBe(expectedOutput);
    expect(isPalindromePermutation2(input)).toBe(expectedOutput);
  });
});

describe('isPalindromePermutation performance', () => {
  it('performs well for large inputs', () => {
    const input = 'a'.repeat(10 ** 6);
    const expectedOutput = true;

    const start1 = process.hrtime();
    const result1 = isPalindromePermutation(input);
    const end1 = process.hrtime(start1);
    const executionTime1 = end1[0] * 1000 + end1[1] / 1000000; // Convert to milliseconds
    expect(result1).toBe(expectedOutput);

    const start2 = process.hrtime();
    const result2 = isPalindromePermutation2(input);
    const end2 = process.hrtime(start2);
    const executionTime2 = end2[0] * 1000 + end2[1] / 1000000; // Convert to milliseconds
    expect(result2).toBe(expectedOutput);

    const acceptableExecutionTime = 100; // Specify the acceptable execution time in milliseconds
    expect(executionTime1).toBeLessThanOrEqual(acceptableExecutionTime);
    expect(executionTime2).toBeLessThanOrEqual(acceptableExecutionTime);
  });
});

import { characterReplacement } from './characterReplacement';

describe('characterReplacement', () => {
  // Positive Test Cases
  it('should handle strings where entire string can be converted', () => {
    expect(characterReplacement('ABAB', 2)).toBe(4);
    expect(characterReplacement('AABABBA', 1)).toBe(4);
  });

  it('should handle strings with no replacements needed', () => {
    expect(characterReplacement('AAAA', 2)).toBe(4);
  });

  it('should handle the case where k equals string length', () => {
    expect(characterReplacement('ABCD', 4)).toBe(4);
  });

  // Negative Test Cases
  it('should handle the case with no replacements allowed', () => {
    expect(characterReplacement('ABAB', 0)).toBe(1);
  });

  it('should handle empty string', () => {
    expect(characterReplacement('', 2)).toBe(0);
  });

  // Edge Cases
  it('should handle the case where k is greater than string length', () => {
    expect(characterReplacement('ABC', 5)).toBe(3);
  });

  it('should handle very long strings efficiently', () => {
    const longString = 'A'.repeat(10000) + 'B'.repeat(10000);
    expect(characterReplacement(longString, 5)).toBe(10005);
  });

  it('should handle single character string', () => {
    expect(characterReplacement('A', 1)).toBe(1);
  });

  // Additional tests for any specific edge cases or negative scenarios can be added here
});

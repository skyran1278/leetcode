import { isPowerOfFour } from './isPowerOfFour';

// Jest test suite
describe('isPowerOfFour', () => {
  it('should return true for a power of four (e.g., 16)', () => {
    expect(isPowerOfFour(16)).toBe(true);
  });

  it('should return false for a non-power of four (e.g., 5)', () => {
    expect(isPowerOfFour(5)).toBe(false);
  });

  it('should return true for n = 1', () => {
    expect(isPowerOfFour(1)).toBe(true);
  });

  it('should return false for negative numbers', () => {
    expect(isPowerOfFour(-16)).toBe(false);
  });

  it('should return false for zero', () => {
    expect(isPowerOfFour(0)).toBe(false);
  });

  it('should return true for a large power of four', () => {
    expect(isPowerOfFour(1073741824)).toBe(true); // 4^15
  });

  it('should return false for a non-integer value', () => {
    expect(isPowerOfFour(6.25)).toBe(false);
  });

  it('should return false for a non-integer value close to 4^x', () => {
    expect(isPowerOfFour(63.999)).toBe(false);
  });
});

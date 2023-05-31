import { oneAway, oneAway2 } from './OneAway'; // Replace 'your-module' with the actual module path

describe('oneAway', () => {
  it('should return true for strings that are one edit away', () => {
    expect(oneAway('pale', 'ple')).toBe(true);
    expect(oneAway('pales', 'pale')).toBe(true);
    expect(oneAway('pale', 'bale')).toBe(true);
    expect(oneAway('pale', 'pale')).toBe(true);
    expect(oneAway('abcde', 'abfde')).toBe(true);
    expect(oneAway('abcde', 'abcdef')).toBe(true);
  });

  it('should return false for strings that are more than one edit away', () => {
    expect(oneAway('pale', 'bake')).toBe(false);
    expect(oneAway('abcde', 'afgde')).toBe(false);
    expect(oneAway('abcde', 'abcdefg')).toBe(false);
    expect(oneAway('abcde', 'cbcd')).toBe(false);
  });
});

describe('oneAway2', () => {
  it('should return true for strings that are one edit away', () => {
    expect(oneAway2('pale', 'ple')).toBe(true);
    expect(oneAway2('pales', 'pale')).toBe(true);
    expect(oneAway2('pale', 'bale')).toBe(true);
    expect(oneAway2('pale', 'pale')).toBe(true);
    expect(oneAway2('abcde', 'abfde')).toBe(true);
    expect(oneAway2('abcde', 'abcdef')).toBe(true);
  });

  it('should return false for strings that are more than one edit away', () => {
    expect(oneAway2('pale', 'bake')).toBe(false);
    expect(oneAway2('abcde', 'afgde')).toBe(false);
    expect(oneAway2('abcde', 'abcdefg')).toBe(false);
    expect(oneAway2('abcde', 'cbcd')).toBe(false);
  });
});

describe('Performance comparison', () => {
  it('should compare the performance of oneAway and oneAway2', () => {
    const longStr1 = 'a'.repeat(1000000);
    const longStr2 = 'b'.repeat(1000000);

    const startTime1 = process.hrtime();
    oneAway(longStr1, longStr2);
    const endTime1 = process.hrtime(startTime1);
    const executionTime1 = endTime1[0] * 1000 + endTime1[1] / 1000000; // Convert to milliseconds

    const startTime2 = process.hrtime();
    oneAway2(longStr1, longStr2);
    const endTime2 = process.hrtime(startTime2);
    const executionTime2 = endTime2[0] * 1000 + endTime2[1] / 1000000; // Convert to milliseconds

    expect(executionTime2).toBeLessThanOrEqual(executionTime1 / 3);
  });
});

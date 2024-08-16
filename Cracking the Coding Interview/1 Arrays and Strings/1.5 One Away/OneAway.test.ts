import { oneAway2 } from './OneAway';

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

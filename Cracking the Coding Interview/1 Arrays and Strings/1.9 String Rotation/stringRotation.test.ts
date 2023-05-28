import { stringRotation } from './stringRotation';

describe('stringRotation', () => {
  it(`returns true if s2 is a rotation of s1`, () => {
    expect(stringRotation('waterbottle', 'erbottlewat')).toBe(true);
  });

  it(`returns false if s2 is not a rotation of s1`, () => {
    expect(stringRotation('waterbottle', 'rbottlewatt')).toBe(false);
  });

  it('returns false if s1 and s2 have different lengths', () => {
    const s1 = 'waterbottle';
    const s2 = 'bottler';
    expect(stringRotation(s1, s2)).toBe(false);
  });
});

import { oneAway, oneAway2 } from './OneAway';

test('oneAway', () => {
  expect(oneAway('pale', 'ple')).toBe(true);
  expect(oneAway('pales', 'pale')).toBe(true);
  expect(oneAway('pale', 'bale')).toBe(true);
  expect(oneAway('pale', 'bake')).toBe(false);
  expect(oneAway('pale', 'paleAe')).toBe(false);
  expect(oneAway('pale', 'baleE')).toBe(false);

  console.time('oneAway');
  for (let index = 0; index < 100000; index++) {
    oneAway('pale', 'ple');
    oneAway('pales', 'pale');
    oneAway('pale', 'bale');
    oneAway('pale', 'bake');
  }
  console.timeEnd('oneAway');
});

test('oneAway2', () => {
  expect(oneAway2('pale', 'ple')).toBe(true);
  expect(oneAway2('pales', 'pale')).toBe(true);
  expect(oneAway2('pale', 'bale')).toBe(true);
  expect(oneAway2('pale', 'bake')).toBe(false);
  expect(oneAway2('pale', 'paleAe')).toBe(false);
  expect(oneAway2('pale', 'baleE')).toBe(false);

  console.time('oneAway2');
  for (let index = 0; index < 100000; index++) {
    oneAway2('pale', 'ple');
    oneAway2('pales', 'pale');
    oneAway2('pale', 'bale');
    oneAway2('pale', 'bake');
  }
  console.timeEnd('oneAway2');
});

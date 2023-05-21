// test stringCompression
//   ✓ should return a2b1c5a3 for aabcccccaaa
import { stringCompression, stringCompression2 } from './stringCompression';

test('stringCompression', () => {
  expect(stringCompression('aabcccccaaa')).toEqual('a2b1c5a3');
  expect(stringCompression('abca')).toEqual('abca');

  console.time('stringCompression if can be compressed');
  stringCompression('abcaaaaaaa'.repeat(1000000));
  console.timeEnd('stringCompression if can be compressed');
  console.time('stringCompression if cannot be compressed');
  stringCompression('abca'.repeat(1000000));
  console.timeEnd('stringCompression if cannot be compressed');
});

test('stringCompression2', () => {
  expect(stringCompression2('aabcccccaaa')).toEqual('a2b1c5a3');
  expect(stringCompression2('abca')).toEqual('abca');

  console.time('stringCompression2 if can be compressed');
  stringCompression2('abcaaaaaaa'.repeat(1000000));
  console.timeEnd('stringCompression2 if can be compressed');
  console.time('stringCompression2 if cannot be compressed');
  stringCompression2('abca'.repeat(1000000));
  console.timeEnd('stringCompression2 if cannot be compressed');
});

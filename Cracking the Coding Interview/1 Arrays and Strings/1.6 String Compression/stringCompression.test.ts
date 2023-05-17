// test stringCompression
//   ✓ should return a2b1c5a3 for aabcccccaaa
import { stringCompression } from './stringCompression';

test('stringCompression', () => {
  expect(stringCompression('aabcccccaaa')).toEqual('a2b1c5a3');
  expect(stringCompression('abca')).toEqual('abca');
});

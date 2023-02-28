// /**
//  * version 1: two for loop
//  *
//  * @param {number[]} nums
//  * @param {number} target
//  * @return {number[]}
//  */
// const twoSum = (nums, target) => {
//   for (let i = 0; i < nums.length; i += 1) {
//     const num1 = nums[i];
//     for (let j = i + 1; j < nums.length; j += 1) {
//       const num2 = nums[j];
//       if (num1 + num2 === target) {
//         return [i, j];
//       }
//     }
//   }
//   return [];
// };

/**
 * version 2: one for loop
 *
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const twoSum = (nums, target) => {
  const map = {};

  for (let i = 0; i < nums.length; i += 1) {
    const num = nums[i];
    const rem = target - num;

    if (map[rem] !== undefined) {
      return [map[rem], i];
    }

    map[num] = i;
  }
  return [];
};

console.log(twoSum([2, 7, 11, 15], 9));

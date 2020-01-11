/**
 * @param {number[]} nums
 * @return {number[][]}
 */
const threeSum = (nums) => {
  const x = [];
  nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length - 2; i += 1) {
    let j = i + 1;
    let k = nums.length;
    while (j < k) {
      if (nums[i] + nums[j] + nums[k] === 0) {
        x.push([nums[i], nums[j], nums[k]]);
      }
      j += 1;
      k -= 1;
      // while (nums[j] === nums[j + 1] && j < k) {
      //   j += 1;
      // }
      // while (nums[k - 1] === nums[k] && j < k) {
      //   k -= 1;
      // }
    }
  }
  return x;
};

console.log(threeSum([-1, 0, 1, 2, -1, -4]));

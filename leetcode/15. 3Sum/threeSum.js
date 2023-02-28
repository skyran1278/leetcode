/**
 * @param {number[]} nums
 * @return {number[][]}
 */
const threeSum = (nums) => {
  const x = [];
  nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length - 2; i += 1) {
    if (nums[i] > 0) {
      return x;
    }
    if (nums[i] !== nums[i - 1]) {
      let j = i + 1;
      let k = nums.length - 1;
      while (j < k) {
        if (nums[i] + nums[j] + nums[k] === 0) {
          x.push([nums[i], nums[j], nums[k]]);
          j += 1;
          k -= 1;
          while (j < k && nums[j] === nums[j - 1]) {
            j += 1;
          }
          while (j < k && nums[k] === nums[k + 1]) {
            k -= 1;
          }
        } else if (nums[i] + nums[j] + nums[k] > 0) {
          k -= 1;
        } else {
          j += 1;
        }
      }
    }
  }
  return x;
};

console.log(threeSum([-1, 0, 1, 2, -1, -4]));
console.log(threeSum([-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6]));

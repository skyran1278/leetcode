/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
const threeSumClosest = (nums, target) => {
  let min = Infinity;
  nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length - 2; i += 1) {
    let j = i + 1;
    let k = nums.length - 1;
    while (j < k) {
      const value = nums[i] + nums[j] + nums[k];
      if (value === target) {
        return target;
      }
      if (value > target) {
        k -= 1;
      } else {
        j += 1;
      }
      if (Math.abs(value - target) < Math.abs(min - target)) {
        min = value;
      }
    }
  }
  return min;
};

console.log(threeSumClosest([-1, 2, 1, -4], 1));

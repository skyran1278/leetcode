/**
 * @param {number[]} nums
 * @return {number}
 */
const removeDuplicatesV2 = (nums) => {
  let i = 0;
  while (i < nums.length) {
    if (nums[i] === nums[i - 1]) {
      nums.splice(i, 1);
    } else {
      i += 1;
    }
  }
  return nums.length;
};

const removeDuplicates = (nums) => {
  let i = 0;
  for (let j = 0; j < nums.length; j++) {
    if (nums[j] !== nums[i]) {
      nums[++i] = nums[j];
    }
  }
  return ++i;
};

console.log(removeDuplicates([1, 2, 2, 3, 4]));

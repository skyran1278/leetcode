/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
const findMedianSortedArrays = (nums1, nums2) => {
  const nums = nums1.concat(nums2).sort((a, b) => a - b);
  const { length } = nums;
  return length % 2 === 0
    ? ((nums[length / 2 - 1] + nums[length / 2]) / 2)
    : nums[(length - 1) / 2];
};

console.log(findMedianSortedArrays([1, 3], [2]));
console.log(findMedianSortedArrays([1, 2], [3, 4]));

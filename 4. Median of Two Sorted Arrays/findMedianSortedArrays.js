/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
// const findMedianSortedArrays = (nums1, nums2) => {
//   const nums = nums1.concat(nums2).sort((a, b) => a - b);
//   const { length } = nums;
//   return length % 2 === 0
//     ? ((nums[length / 2 - 1] + nums[length / 2]) / 2)
//     : nums[(length - 1) / 2];
// };

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
const findMedianSortedArrays = (nums1, nums2) => {
  if (nums1.length > nums2.length) findMedianSortedArrays(nums2, nums1);

  let i = Math.floor(nums1.length / 2);
  let j = Math.ceil(nums2.length / 2);
  while (i > 0 && i < nums1.length && (nums1[i - 1] > nums2[j] || nums2[j - 1] > nums1[i])) {
    if (nums1[i - 1] > nums2[j]) {
      i -= 1;
      j += 1;
    }
    if (nums2[j - 1] > nums1[i]) {
      i += 1;
      j -= 1;
    }
  }
  if (i === 0 || i === nums1.length) {
    return (nums1[i], nums2[j]) / 2;
  }
  if (2 * (i + j) > nums1.length + nums2.length) {
    return Math.max(nums1[i - 1], nums2[j - 1]);
  }
  if (2 * (i + j) < nums1.length + nums2.length) {
    return Math.min(nums1[i], nums2[j]);
  }
  return (Math.max(nums1[i - 1], nums2[j - 1]) + Math.min(nums1[i], nums2[j])) / 2;
};


console.log(findMedianSortedArrays([1, 3], [2]));
console.log(findMedianSortedArrays([1, 2], [3, 4]));

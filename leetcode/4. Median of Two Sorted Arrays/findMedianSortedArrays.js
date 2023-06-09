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
  if (nums1.length > nums2.length) return findMedianSortedArrays(nums2, nums1);

  let i = Math.floor(nums1.length / 2);
  let j = Math.ceil(nums2.length / 2);
  let leftI;
  let rightI;
  let leftJ;
  let rightJ;
  do {
    leftI = i === 0 ? -Infinity : nums1[i - 1];
    rightI = i === nums1.length ? Infinity : nums1[i];
    leftJ = j === 0 ? -Infinity : nums2[j - 1];
    rightJ = j === nums2.length ? Infinity : nums2[j];
    if (leftI > rightJ) {
      i -= 1;
      j += 1;
    }
    if (leftJ > rightI) {
      j -= 1;
      i += 1;
    }
  } while (leftI > rightJ || leftJ > rightI);
  if (2 * (i + j) > nums1.length + nums2.length) {
    return Math.max(leftI, leftJ);
  }
  if (2 * (i + j) < nums1.length + nums2.length) {
    return Math.min(rightI, rightJ);
  }
  return (Math.max(leftI, leftJ) + Math.min(rightI, rightJ)) / 2;
};

console.log(findMedianSortedArrays([1, 3], [2]));
console.log(findMedianSortedArrays([1, 2], [3, 4]));

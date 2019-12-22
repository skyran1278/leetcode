/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
const findMedianSortedArrays = (nums1, nums2) => {
  let i = nums2.length;
  nums1.forEach((v) => {
    while (!(v <= nums2[i] && v >= nums2[i - 1])) {
      if (v < nums2[i - 1]) {
        i = Math.round(i / 2);
      } else if (v > nums2[i]) {
        i = Math.round((3 * i) / 2);
      }
      nums2.splice(i, 0, v);
    }
  });
  return i % 2 === 0 ? nums2[i / 2] : (nums2[Math.ceil(i / 2)] + nums2[Math.floor(i / 2)]);
};

console.log(findMedianSortedArrays([1, 3], [2]));

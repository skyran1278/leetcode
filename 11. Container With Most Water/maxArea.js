/**
 * @param {number[]} height
 * @return {number}
 */
// const maxArea = (height) => {
//   let max = 0;
//   for (let i = 0; i < height.length; i += 1) {
//     for (let j = i + 1; j < height.length; j += 1) {
//       const area = Math.min(height[i], height[j]) * (j - i);
//       max = area > max ? area : max;
//     }
//   }
//   return max;
// };

/**
 * @param {number[]} height
 * @return {number}
 */
const maxArea = (height) => {
  let max = 0;
  let i = 0;
  let j = height.length;
  while (i < j) {
    const area = Math.min(height[i], height[j]) * (j - i);
    max = area > max ? area : max;
    if (height[i] < height[j]) {
      i += 1;
    } else {
      j -= 1;
    }
  }
  return max;
};

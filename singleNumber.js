/**
 * @param {number[]} nums
 * @return {number}
 */
const singleNumber = (nums) => {
  const oneNumbers = {};
  const twiceNumbers = {};
  nums.forEach((num) => {
    if (twiceNumbers[num]) {
      delete oneNumbers[num];
      twiceNumbers[num] = true;
    } else {
      oneNumbers[num] = num;
      twiceNumbers[num] = true;
    }
  });
  return Object.entries(oneNumbers)[0][0];
};

console.log(singleNumber([1, 1, 2, 5, 5]));
// const map = {};
// console.log(map[1]);

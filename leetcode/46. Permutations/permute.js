/**
 * @param {number[]} nums
 * @return {number[][]}
 */
const permute = (nums) => {
  // 最終輸出的排列組合
  const permutations = [];

  const backtrack = (selects, rest) => {
    const { length } = rest;
    if (length === 0) {
      permutations.push([...selects]);
      return;
    }

    for (let i = 0; i < length; i += 1) {
      // 做選擇
      selects.push(rest.splice(i, 1)[0]);

      // 往下遍歷
      backtrack(selects, rest);

      // 回朔選擇
      rest.splice(i, 0, selects.pop());
    }
  };

  backtrack([], nums);

  return permutations;
};

console.log(permute([1, 2, 3]));

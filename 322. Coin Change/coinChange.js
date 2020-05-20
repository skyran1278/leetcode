/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
// const coinChange = (coins, amount) => {
//   // const min = Math.min(coins)
//   // const max = Math.max(coins)

//   // const memo = Array(max - min)
//   const memo = Array(amount + 1)

//   const dp = (subAmount) => {
//       if (memo[subAmount]) return memo[subAmount]
//       let element = 0
//       for (let index = 1; index < subAmount; index += 1) {
//         element += dp(index);

//       }

//       memo[subAmount] =

//   }
//   for (let index = 1; index < memo.length; index += 1) {
//     const element = memo[index];

//   }
// };

const coinChange = (coins, amount) => {
  let num = 0;
  const dp = (coins, amount) => {
    for (let index = 0; index < coins.length; index += 1) {
      const subProblem = amount - coins[index];
      if (subProblem === 0) return 1;
      if (subProblem > 0) {
        num += coinChange(coins, subProblem);
      }
    }
    return -1;
  };
  dp(coins, amount);
};

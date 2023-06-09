/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
const coinChange = (coins, amount) => {
  // 加速
  coins.sort((a, b) => b - a);

  const memo = Array(amount + 1);
  const dp = (n) => {
    // base case
    if (n === 0) return 0;
    if (n < 0) return -1;

    if (memo[n]) return memo[n];

    let num = Infinity;
    coins.forEach((coin) => {
      const subProblem = dp(n - coin);
      if (subProblem >= 0) {
        num = Math.min(num, subProblem + 1);
      }
    });

    memo[n] = Number.isFinite(num) ? num : -1;

    return memo[n];
  };
  return dp(amount);
};

const coinChange = (coins, amount) => {
  coins.sort((a, b) => b - a);
  // 初始化
  const dp = Array(amount + 1).fill(Infinity);
  dp[0] = 0;

  for (let index = 0; index < dp.length; index += 1) {
    coins.forEach((coin) => {
      const subProblem = dp[index - coin];
      if (subProblem >= 0) {
        dp[index] = Math.min(dp[index], subProblem + 1);
      }
    });
  }
  return Number.isFinite(dp[amount]) ? dp[amount] : -1;
};

console.log(coinChange([1, 2, 5], 11));
console.log(coinChange([2], 3));

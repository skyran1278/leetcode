/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
const coinChange = (coins, amount) => {
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
  const dp = Array(amount + 1);
  dp[0] = 0;
  for (let index = 0; index < dp.length; index += 1) {
    const element = dp[index];
    coins.forEach((coin) => {
      const subProblem = dp(n - coin);
      if (subProblem >= 0) {
        num = Math.min(num, subProblem + 1);
      }
    });
  }
  return dp[amount]
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

console.log(coinChange([1, 2, 5], 11));
console.log(coinChange([2], 3));

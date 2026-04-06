#include <algorithm>
#include <array>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 9m 7s
 * @brief 4m 9s
 * @brief 4m 4s
 * @brief 2m 57s
 * @brief 7m 50s
 *
 * Define dp[i, 0] as the maximum profit up to day i without holding stock,
 * and dp[i, 1] as maximum profit up to day i holding stock.
 *
 * dp[i, 0] = max(dp[i - 1, 0], dp[i - 1, 1] + price - fee)
 * dp[i, 1] = max(dp[i - 1, 1], dp[i - 1, 0] - price)
 *
 * O(n)
 * O(n)
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = static_cast<int>(prices.size());
    vector<array<int, 2>> dp(n, {0, 0});
    dp[0] = {0, -prices[0]};

    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], prices[i] + dp[i - 1][1] - fee);
      dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
    }

    return dp[n - 1][0];
  }
};

int main() {
  Solution s;
  vector<int> prices{1, 3, 2, 8, 4, 9};
  int fee = 2;
  s.maxProfit(prices, fee);

  return 0;
}

#include <algorithm>
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
 * @brief 9 m 7 s
 * @brief 4 m 9 s
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
  // prices = [1,3,2,8,4,9], fee = 2
  int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int>> dp(prices.size(), vector<int>(2));

    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    /**
     * dp
     * 1 0 -1
     * 3 0 -1
     * 2 0 -1
     * 8 5 -1
     * 4 5 1
     * 9 8 1
     */
    for (size_t i = 1; i < prices.size(); i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    return dp[prices.size() - 1][0];
  }
};

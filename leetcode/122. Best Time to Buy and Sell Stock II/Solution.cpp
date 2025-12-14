#include <climits>
#include <vector>

using namespace std;

/**
 * @brief 27 m 27 s
 * @brief 3 m 8 s
 * @brief 2 m 58 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int accProfit = 0;
    for (size_t i = 1; i < prices.size(); i++) {
      int profit = prices[i] - prices[i - 1];
      if (profit > 0) {
        accProfit += profit;
      }
    }

    return accProfit;
  }
};

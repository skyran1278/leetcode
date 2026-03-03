#include <climits>
#include <vector>

using namespace std;

/**
 * @brief 27m 27s
 * @brief 3m 8s
 * @brief 2m 58s
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

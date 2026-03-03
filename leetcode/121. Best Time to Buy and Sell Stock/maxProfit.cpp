#include <vector>

using namespace std;

/**
 * @brief 31m 5s
 * @brief 11m 26s
 * @brief 2m 51s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // prices = [7,1,5,3,6,4]
  int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int minPrice = __INT_MAX__;

    for (auto&& price : prices) {
      int profit = price - minPrice;
      if (profit > maxProfit) {
        maxProfit = profit;  // 5
      }

      if (price < minPrice) {
        minPrice = price;  // 1
      }
    }

    return maxProfit;
  }
};

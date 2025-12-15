#include <vector>

using namespace std;

/**
 * @brief 31 m 5 s
 * @brief 11 m 26 s
 * @brief 2 m 51 s
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

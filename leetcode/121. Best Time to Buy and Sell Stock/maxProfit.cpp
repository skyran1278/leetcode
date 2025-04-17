#include <climits>
#include <vector>

using namespace std;

/**
 * @brief 31 m 5 s
 * O(n)
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (auto&& price : prices) {
      int profit = price - minPrice;
      if (profit > maxProfit) {
        maxProfit = profit;
      }
      if (price < minPrice) {
        minPrice = price;
      }
    }

    return maxProfit;
  }
};

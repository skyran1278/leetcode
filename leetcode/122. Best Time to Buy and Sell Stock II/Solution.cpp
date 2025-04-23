#include <climits>
#include <vector>

using namespace std;

/**
 * @brief 27 m 27 s
 * O(n)
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int accPrice = 0;
    int lastPrice = prices[0];
    for (auto&& price : prices) {
      if (price > lastPrice) {
        accPrice += price - lastPrice;
      }
      lastPrice = price;
    }

    return accPrice;
  }
};

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
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // prices = [1,3,2,8,4,9], fee = 2
  int maxProfit(vector<int>& prices, int fee) {
    int cash = 0;
    int hold = -prices[0];  // hold = -1;

    for (size_t i = 1; i < prices.size(); i++) {
      cash = max(cash, hold + prices[i] - fee);  // cash = 8;
      hold = max(hold, cash - prices[i]);        // hold = 1;
    }

    return cash;
  }
};

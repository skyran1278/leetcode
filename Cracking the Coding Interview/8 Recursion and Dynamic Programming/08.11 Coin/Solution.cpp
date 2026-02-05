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
 * @brief
 * O(n)
 * O(n)
 */
class Solution {
 public:
  int waysToChange(int n) {
    vector<int> coins = {1, 5, 10, 25};

    vector<int> dp(n + 1);
    dp[0] = 1;

    for (auto&& coin : coins) {
      for (int i = coin; i <= n; i++) {
        dp[i] = (dp[i] + dp[i - coin]) % 1000000007;
      }
    }

    return dp[n];
  }
};

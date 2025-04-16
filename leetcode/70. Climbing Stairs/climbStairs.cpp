#include <vector>

using namespace std;

/**
 * @brief 11 m 4 s
 * O(n)
 */
class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    }

    vector<int> dp = {1, 2};
    for (size_t i = 2; i < n; i++) {
      int r = dp[0] + dp[1];
      dp[0] = dp[1];
      dp[1] = r;
    }

    return dp[1];
  }
};

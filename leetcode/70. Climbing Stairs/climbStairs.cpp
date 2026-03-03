#include <vector>

using namespace std;

/**
 * @brief 11m 4s
 * @brief 10m 48s
 * @brief 8m 45s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // n = 4
  // 1. 1 step + 1 step + 1 step + 1 step
  // 2. 1 step + 2 steps + 1 step
  // 3. 2 steps + 1 step + 1 step
  // 4. 1 step + 1 step + 2 steps
  // 5. 2 steps + 2 steps
  int climbStairs(int n) {
    vector<int> dp = {1, 1};

    for (size_t i = 0; i < n - 1; i++) {
      int next = dp[0] + dp[1];
      dp[0] = dp[1];  // dp = {2, 3}
      dp[1] = next;
    }

    return dp[1];
  }
};

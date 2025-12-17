#include <vector>

using namespace std;

/**
 * @brief 12 m 14 s
 * @brief 6 m 24 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // n = 4
  int fib(int n) {
    if (n == 0) return 0;

    vector<int> dp = {0, 1};
    for (size_t i = 1; i < n; i++) {
      int next = dp[0] + dp[1];
      dp[0] = dp[1];
      dp[1] = next;
    }
    return dp[1];
  }
};

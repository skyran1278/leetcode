#include <vector>

using namespace std;

/**
 * @brief 12 m 14 s
 * O(n)
 */
class Solution {
 public:
  int fib(int n) {
    vector<int> dp = {0, 1};
    for (size_t i = 0; i < n; i++) {
      int next = dp[0] + dp[1];
      dp[0] = dp[1];
      dp[1] = next;
    }
    return dp[1];
  }
};

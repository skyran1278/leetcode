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
 * @brief 8 m 35 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  int waysToStep(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    vector<long> dp(3);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;

    for (size_t i = 3; i < n; i++) {
      int cur = (dp[0] + dp[1] + dp[2]) % 1000000007;
      dp[0] = dp[1];
      dp[1] = dp[2];
      dp[2] = cur;
    }

    return dp[2];
  }
};

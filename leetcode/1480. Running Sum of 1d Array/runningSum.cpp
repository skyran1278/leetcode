#include <vector>

using namespace std;

/**
 * @brief 3 m 37 s
 * O(n)
 */
class Solution {
 public:
  vector<int> runningSum(vector<int>& nums) {
    vector<int> dp = nums;
    for (size_t i = 0; i < dp.size() - 1; i++) {
      dp[i + 1] = dp[i] + dp[i + 1];
    }
    return dp;
  }
};

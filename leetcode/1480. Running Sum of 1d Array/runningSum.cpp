#include <vector>

using namespace std;

/**
 * @brief 3 m 37 s
 * @brief 2 m 16 s
 * O(n)
 * O(n) for a new result array, or O(1) extra if done in-place
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

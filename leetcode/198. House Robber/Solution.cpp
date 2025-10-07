#include <vector>

using namespace std;

/**
 * @brief 20 m 29 s
 * @brief 9 m 54 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // nums = [1,2,3,1]
  // nums = [2,7,9,3,1]
  // nums = [2,1,1,2]
  int rob(vector<int>& nums) {
    int pre1 = 0;
    int pre2 = 0;
    for (auto&& num : nums) {
      int cur = max(pre2 + num, pre1);
      pre2 = pre1;
      pre1 = cur;
    }

    return pre1;
  }
};

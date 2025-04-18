#include <vector>

using namespace std;

/**
 * @brief 20 m 29 s
 * O(n)
 */
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }

    int first = nums[0];
    int second = max(nums[0], nums[1]);

    for (size_t i = 2; i < n; i++) {
      int tmp = max(first + nums[i], second);
      first = second;
      second = tmp;
    }

    return second;
  }
};

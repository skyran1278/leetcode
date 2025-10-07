#include <vector>

using namespace std;

/**
 * @brief 37 m 42 s
 * @brief 11 m 45 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // nums = [-2,1,-3,4,-1,2,1,-5,4]
  int maxSubArray(vector<int>& nums) {
    int left = 0;
    int largest = nums[0];

    for (auto&& num : nums) {
      left = max(left + num, num);

      if (left > largest) {
        largest = left;
      }
    }

    return largest;
  }
};

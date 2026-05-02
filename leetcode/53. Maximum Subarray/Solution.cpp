#include <vector>

using namespace std;

/**
 * @brief 37m 42s
 * @brief 11m 45s
 * @brief 20m 40s (editorial)
 * @brief 12m 23s (editorial)
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

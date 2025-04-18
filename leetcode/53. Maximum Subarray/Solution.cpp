#include <climits>
#include <vector>

using namespace std;

/**
 * @brief 37 m 42 s
 * O(n)
 */
class Solution {
 public:
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

#include <string>
#include <vector>

using namespace std;

/**
 * @brief 24 m 13 s
 * @brief 6 m 30 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // nums = [1,2,3,4]
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    // Left product pass
    // result = [1, 1, 2, 6]
    int prefix = 1;
    for (int i = 0; i < n; i++) {
      result[i] = prefix;
      prefix *= nums[i];
    }

    // Right product pass
    // result = [24, 12, 8, 6]
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
      result[i] *= suffix;
      suffix *= nums[i];
    }

    return result;
  }
};

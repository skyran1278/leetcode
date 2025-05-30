#include <string>
#include <vector>

using namespace std;

/**
 * @brief 沒寫出來
 * O(n)
 */
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);

    result[0] = 1;
    for (size_t i = 1; i < n; i++) {
      result[i] = result[i - 1] * nums[i - 1];
    }

    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
      result[i] = result[i] * rightProduct;
      rightProduct *= nums[i];
    }

    return result;
  }
};

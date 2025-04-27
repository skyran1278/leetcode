#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int total = 1;
    for (auto&& num : nums) {
      num *= num;
    }

    vector<int> result(nums.size());
    for (size_t i = 0; i < nums.size(); i++) {
      result[i] = total / nums[i];
    }
  }
};

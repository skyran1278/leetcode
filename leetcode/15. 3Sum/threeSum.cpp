#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief 1 hrs 9 m 50 s
 * O(n2)
 */
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size() - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      // Early termination: if nums[i] > 0, then all numbers after are > 0
      if (nums[i] > 0) break;

      size_t left = i + 1;
      size_t right = nums.size() - 1;

      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];

        if (sum > 0) {
          right--;
        } else if (sum < 0) {
          left++;
        } else {
          result.push_back({nums[i], nums[left], nums[right]});
          left++;
          right--;

          // skip duplicates
          while (left < right && nums[left] == nums[left - 1]) left++;
          while (left < right && nums[right] == nums[right + 1]) right--;
        }
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<int> i1 = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> s1 = s.threeSum(i1);
}

#include <vector>

using namespace std;

/**
 * @brief 23 m 59 s
 * @brief 18 m 8 s
 * @brief 16 m 31 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // nums = [1,7,3,6,5,6]
  int pivotIndex(vector<int>& nums) {
    int total = 0;
    for (auto&& num : nums) {
      total += num;
    }

    int left = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      int right = total - left - nums[i];
      if (left == right) {
        return i;
      }
      left += nums[i];
    }

    return -1;
  }
};

int main() {
  Solution s;
  vector<int> s1 = {1, 7, 3, 6, 5, 6};
  s.pivotIndex(s1);
  vector<int> s2 = {2, 5};
  s.pivotIndex(s2);
}

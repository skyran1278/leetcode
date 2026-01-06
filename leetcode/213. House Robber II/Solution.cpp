#include <climits>
#include <vector>

using namespace std;

/**
 * @brief 52 m 48 s
 * @brief 5 m 38 s
 * @brief 4 m 7 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  int rob(vector<int>& nums) {
    size_t n = nums.size();
    if (n == 1) {
      return nums[0];
    }

    return max(robRange(nums, 0, n - 1), robRange(nums, 1, n));
  }

  int robRange(vector<int>& nums, size_t start, size_t end) {
    int pre2 = 0;
    int pre1 = 0;

    for (size_t i = start; i < end; i++) {
      int cur = max(pre2 + nums[i], pre1);
      pre2 = pre1;
      pre1 = cur;
    }

    return pre1;
  }
};

int main() {
  Solution s;

  vector<int> s2 = {1, 2, 3};
  s.rob(s2);

  vector<int> s1 = {2, 3, 2};
  s.rob(s1);
}

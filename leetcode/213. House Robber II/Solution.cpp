#include <climits>
#include <vector>

using namespace std;

/**
 * @brief 52 m 48 s
 * O(n)
 */
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }
    if (n == 2) {
      return max(nums[0], nums[1]);
    }

    return max(_rob(nums, 0, n - 1), _rob(nums, 1, n));
  }

  int _rob(vector<int>& nums, int left, int right) {
    int first = nums[left];
    int second = max(first, nums[left + 1]);

    for (size_t i = left + 2; i < right; i++) {
      int tmp = max(nums[i] + first, second);
      first = second;
      second = tmp;
    }

    return second;
  }
};

int main() {
  Solution s;

  vector<int> s2 = {1, 2, 3};
  s.rob(s2);

  vector<int> s1 = {2, 3, 2};
  s.rob(s1);
}

#include <vector>

using namespace std;

/**
 * @brief 7 m 5 s
 * @brief 9 m 28 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // nums = [1,3,4,2,2]
  int findDuplicate(vector<int>& nums) {
    size_t slow = 0;
    size_t fast = 0;

    do {
      slow = nums[slow];        // slow = 1, 3, 2, 4
      fast = nums[nums[fast]];  // fast = 3, 4, 4, 4
    } while (slow != fast);

    slow = 0;
    while (slow != fast) {
      slow = nums[slow];  // slow = 1, 3, 2
      fast = nums[fast];  // fast = 2, 4, 2
    }

    return fast;
  }
};

int main() {
  Solution s;

  vector<int> s1 = {1, 3, 4, 2, 2};
  s.findDuplicate(s1);
}

#include <vector>

using namespace std;

/**
 * hard, I read answer to solve this problem
 * O(n)
 */
class Solution {
 public:
  // nums = [1,3,4,2,2]
  int findDuplicate(vector<int>& nums) {
    int fast = 0;
    int slow = 0;

    do {
      // fast = 3, slow = 1
      // fast = 4, slow = 3
      // fast = 4, slow = 2
      // fast = 4, slow = 4
      fast = nums[nums[fast]];
      slow = nums[slow];
    } while (fast != slow);

    fast = 0;

    while (fast != slow) {
      // fast = 2, slow = 1
      // fast = 4, slow = 3
      // fast = 2, slow = 2
      fast = nums[fast];
      slow = nums[slow];
    }

    return fast;
  }
};

int main() {
  Solution s;

  vector<int> s1 = {1, 3, 4, 2, 2};
  s.findDuplicate(s1);
}

#include <vector>

using namespace std;

/**
 * hard, I read answer to solve this problem
 * O(n)
 */
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int slowRunner = 0;
    int fastRunner = 0;

    do {
      slowRunner = nums[slowRunner];
      fastRunner = nums[nums[fastRunner]];
    } while (slowRunner != fastRunner);

    slowRunner = 0;

    while (slowRunner != fastRunner) {
      slowRunner = nums[slowRunner];
      fastRunner = nums[fastRunner];
    }

    return slowRunner;
  }
};

int main() {
  Solution s;

  vector<int> s1 = {1, 3, 4, 2, 2};
  s.findDuplicate(s1);
}

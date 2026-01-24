#include <algorithm>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 1 m 25 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  int findMagicIndex(vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] == i) return i;
    }

    return -1;
  }
};

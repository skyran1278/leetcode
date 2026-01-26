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
 * @brief 11 m 45 s
 * O(n 2ⁿ)
 * O(n 2ⁿ)
 */
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> state;
    for (size_t i = 0; i <= nums.size(); i++) {
      backtrack(result, state, nums, i, 0);
    }

    return result;
  }

  void backtrack(vector<vector<int>>& result, vector<int>& state,
                 vector<int>& nums, int n, int select) {
    if (state.size() == n) {
      result.push_back(state);
      return;
    }

    for (size_t i = select; i < nums.size(); i++) {
      state.push_back(nums[i]);
      backtrack(result, state, nums, n, i + 1);
      state.pop_back();
    }
  }
};

#include <vector>

using namespace std;

/**
 * @brief 16 m 37 s
 * @brief 23 m 30 s
 * @brief 10 m 26 s
 * O(n * n!)
 * O(n) for recursion depth, plus O(n * n!) output.
 */
class Solution {
 public:
  // nums = [1,2,3]
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    size_t n = nums.size();       // 3
    vector<bool> used(n, false);  // [false, false, false]
    vector<int> state;

    backtrack(n, nums, used, state, result);

    return result;
  }

  void backtrack(size_t n, vector<int>& nums, vector<bool>& used,
                 vector<int>& state, vector<vector<int>>& result) {
    if (state.size() == n) {
      // [[1, 2, 3]]
      result.push_back(state);
      return;
    }

    for (size_t i = 0; i < n; i++) {
      if (!used[i]) {
        // [1]
        // [1, 2]
        // [1, 2, 3]
        // [1, 3]
        state.push_back(nums[i]);

        // [true, false, false]
        // [true, true, false]
        // [true, true, true]
        // [true, false, true]
        used[i] = true;

        backtrack(n, nums, used, state, result);

        // [1, 2]
        // [1]
        state.pop_back();

        // [true, true, false]
        // [true, false, false]
        used[i] = false;
      }
    }
  }
};

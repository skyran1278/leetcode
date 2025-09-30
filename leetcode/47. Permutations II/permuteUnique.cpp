#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 30 m 31 s
 * @brief 32 m 46 s
 * O(n * n!)
 * O(n) for recursion stack, O(n * n!) for results.
 *
 */
class Solution {
 public:
  // nums = [1,1,2]
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> state;
    size_t n = nums.size();
    vector<bool> used(n, false);

    sort(nums.begin(), nums.end());

    backtrack(n, nums, used, state, result);

    return result;
  }

  void backtrack(size_t n, vector<int>& nums, vector<bool>& used,
                 vector<int>& state, vector<vector<int>>& result) {
    // Base Case: all elements are used
    if (state.size() == n) {
      result.push_back(state);
      return;
    }

    for (size_t i = 0; i < n; i++) {
      // If element is already used, skip
      if (used[i]) {
        continue;
      }

      // Skip duplicates:
      // Only proceed if it's either the first element of its group
      // or the identical predecessor has already been used in this permutation.
      if ((i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
        continue;
      }

      // Choose
      state.push_back(nums[i]);
      used[i] = true;

      // Explore
      backtrack(n, nums, used, state, result);

      // Backtrack
      state.pop_back();
      used[i] = false;
    }
  }
};

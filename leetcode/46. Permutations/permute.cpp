#include <vector>

using namespace std;

/**
 * @brief 16 m 37 s
 * O(n * n!)
 * n! for the total number of permutations.
 * n for copying each permutation into the result list.
 */
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> state;
    size_t n = nums.size();
    vector<bool> choose(n, false);
    vector<vector<int>> result;
    backTracking(state, n, nums, choose, result);

    return result;
  }

  void backTracking(vector<int>& state, int n, vector<int>& nums,
                    vector<bool>& choices, vector<vector<int>>& result) {
    if (state.size() == n) {
      result.push_back(state);
      return;
    }

    for (size_t i = 0; i < nums.size(); i++) {
      if (!choices[i]) {
        state.push_back(nums[i]);
        choices[i] = true;

        backTracking(state, n, nums, choices, result);

        choices[i] = false;
        state.pop_back();
      }
    }
  }
};

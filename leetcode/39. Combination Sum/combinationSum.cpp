#include <vector>

using namespace std;

/**
 * @brief 16 m 27 s
 * O(2^target)
 */
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> state;
    vector<vector<int>> result;
    dfs(state, target, candidates, 0, result);
    return result;
  }

  void dfs(vector<int>& state, int target, vector<int>& candidates,
           int firstIndex, vector<vector<int>>& result) {
    if (target == 0) {
      result.emplace_back(state);
      return;
    }

    for (size_t i = firstIndex; i < candidates.size(); i++) {
      int c = candidates[i];
      if (c <= target) {
        state.emplace_back(c);
        dfs(state, target - c, candidates, i, result);
        state.pop_back();
      }
    }
  }
};

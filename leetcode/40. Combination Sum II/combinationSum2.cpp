#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 18 m 21 s
 *
 */
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> state;
    vector<vector<int>> result;

    sort(candidates.begin(), candidates.end());

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
      if (i > firstIndex && candidates[i] == candidates[i - 1]) continue;
      if (target - candidates[i] < 0) break;

      state.emplace_back(candidates[i]);
      dfs(state, target - candidates[i], candidates, i + 1, result);
      state.pop_back();
    }
  }
};

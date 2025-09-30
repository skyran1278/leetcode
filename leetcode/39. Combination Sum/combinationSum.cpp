#include <vector>

using namespace std;

/**
 * @brief 16 m 27 s
 * @brief 13 m 52 s
 * O(n^(target/minCandidate))
 * O(target)
 */
class Solution {
 public:
  // candidates = [2,3,6,7], target = 7
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> state;

    backtrack(candidates, 0, state, target, result);

    return result;
  }

  void backtrack(vector<int>& candidates, size_t start, vector<int>& state,
                 int target, vector<vector<int>>& result) {
    if (target == 0) {
      result.push_back(state);
      return;
    }

    for (size_t i = start; i < candidates.size(); i++) {
      int num = candidates[i];
      if (target - num < 0) {
        continue;
      }

      state.push_back(num);

      // state = [2], target = 5
      // state = [2, 2], target = 3
      // state = [2, 2, 3], target = 0
      backtrack(candidates, i, state, target - num, result);

      state.pop_back();
    }
  }
};

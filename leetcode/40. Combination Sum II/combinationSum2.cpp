#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 18 m 21 s
 * @brief 22 m 27 s
 * O(2^n)
 * O(n)
 */
class Solution {
 public:
  //  candidates = [10,1,2,7,6,1,5], target = 8
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> state;

    // [1,1,2,5,6,7,10]
    sort(candidates.begin(), candidates.end());

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
        break;
      }

      if (i > start && num == candidates[i - 1]) {
        continue;
      }

      state.push_back(num);

      // state = [1], target = 7
      // state = [1, 1], target = 6
      backtrack(candidates, i + 1, state, target - num, result);

      state.pop_back();
    }
  }
};

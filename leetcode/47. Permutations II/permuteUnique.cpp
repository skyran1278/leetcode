#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 30 m 31 s
 * O(n * n!)
 */
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<int> state;
    vector<bool> used(nums.size(), false);
    vector<vector<int>> result;
    dfs(state, used, nums, result);
    return result;
  }

  void dfs(vector<int>& state, vector<bool>& used, vector<int>& nums,
           vector<vector<int>>& result) {
    if (state.size() == nums.size()) {
      result.emplace_back(state);
      return;
    }

    unordered_set<int> duplicates;
    for (size_t i = 0; i < nums.size(); i++) {
      if (!used[i] && duplicates.find(nums[i]) == duplicates.end()) {
        duplicates.emplace(nums[i]);
        used[i] = true;
        state.emplace_back(nums[i]);

        dfs(state, used, nums, result);

        used[i] = false;
        state.pop_back();
      }
    }
  }
};

int main() {
  Solution s;
  vector<int> s1 = {1, 1, 2};
  s.permuteUnique(s1);
}

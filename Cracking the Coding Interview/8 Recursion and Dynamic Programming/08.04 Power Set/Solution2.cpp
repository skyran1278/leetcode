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
 * @brief 6 m 42 s
 * O(n 2ⁿ)
 * O(n 2ⁿ)
 */
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, 0, current, result);
    return result;
  }

 private:
  void backtrack(vector<int>& nums, int start, vector<int>& current,
                 vector<vector<int>>& result) {
    // Add the current subset (a snapshot of 'current') to result
    result.push_back(current);

    for (int i = start; i < nums.size(); ++i) {
      // Include nums[i]
      current.push_back(nums[i]);

      // Move to next element
      backtrack(nums, i + 1, current, result);

      // Backtrack: Remove nums[i] to try different combinations
      current.pop_back();
    }
  }
};

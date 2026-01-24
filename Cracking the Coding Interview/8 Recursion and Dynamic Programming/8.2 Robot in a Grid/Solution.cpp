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
 * @brief 1 hrs 0 m 56 s
 * O(rc)
 * O(rc)
 */
class Solution {
 public:
  vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>> result;
    vector<vector<int>> state;
    vector<vector<bool>> visited(obstacleGrid.size(),
                                 vector<bool>(obstacleGrid[0].size()));
    backtrack(result, state, visited, obstacleGrid, 0, 0);
    return result;
  }

  void backtrack(vector<vector<int>>& result, vector<vector<int>>& state,
                 vector<vector<bool>>& visited,
                 vector<vector<int>>& obstacleGrid, int row, int col) {
    if (visited[row][col] || obstacleGrid[row][col] == 1) return;

    state.push_back({row, col});
    visited[row][col] = true;

    if (row == obstacleGrid.size() - 1 && col == obstacleGrid[row].size() - 1) {
      result = state;
      return;
    }

    if (result.empty() && col + 1 < obstacleGrid[row].size()) {
      backtrack(result, state, visited, obstacleGrid, row, col + 1);
    }
    if (result.empty() && row + 1 < obstacleGrid.size()) {
      backtrack(result, state, visited, obstacleGrid, row + 1, col);
    }

    state.pop_back();
  }
};

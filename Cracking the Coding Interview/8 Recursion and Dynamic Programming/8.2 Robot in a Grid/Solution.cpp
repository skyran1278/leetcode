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
 * @brief 21 m 15 s
 * O(rc)
 * O(rc)
 */
class Solution {
 public:
  vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>> path;
    vector<vector<bool>> visit(obstacleGrid.size(),
                               vector<bool>(obstacleGrid[0].size()));
    backtrack(path, obstacleGrid, visit, 0, 0);
    return path;
  }

  bool backtrack(vector<vector<int>>& path, vector<vector<int>>& obstacleGrid,
                 vector<vector<bool>>& visit, int row, int col) {
    if (visit[row][col] || obstacleGrid[row][col] == 1) return false;

    path.push_back({row, col});
    visit[row][col] = true;

    if (row == obstacleGrid.size() - 1 && col == obstacleGrid[0].size() - 1)
      return true;

    if (row + 1 < obstacleGrid.size() &&
        backtrack(path, obstacleGrid, visit, row + 1, col))
      return true;
    if (col + 1 < obstacleGrid[0].size() &&
        backtrack(path, obstacleGrid, visit, row, col + 1))
      return true;

    path.pop_back();
    return false;
  }
};

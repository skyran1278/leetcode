#include <vector>

using namespace std;

/**
 * @brief 16 m 25 s
 * @brief 18 m 58 s
 * O(mn)
 * O(1)
 */
class Solution {
 public:
  // grid = [[1,3,1],[1,5,1],[4,2,1]]
  int minPathSum(vector<vector<int>>& grid) {
    // Fill first row
    for (size_t col = 1; col < grid[0].size(); col++) {
      grid[0][col] += grid[0][col - 1];
    }

    // Fill first column
    for (size_t row = 1; row < grid.size(); row++) {
      grid[row][0] += grid[row - 1][0];
    }

    // Fill rest of grid
    for (size_t row = 1; row < grid.size(); row++) {
      for (size_t col = 1; col < grid[row].size(); col++) {
        grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
      }
    }

    return grid[grid.size() - 1][grid[0].size() - 1];
  }
};

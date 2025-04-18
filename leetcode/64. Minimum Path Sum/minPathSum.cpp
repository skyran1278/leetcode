#include <climits>
#include <vector>

using namespace std;

/**
 * @brief 16 m 25 s
 * O(n)
 */
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    size_t rowSize = grid.size();
    size_t colSize = grid[0].size();
    for (size_t row = 0; row < rowSize; row++) {
      for (size_t col = 0; col < colSize; col++) {
        int previous = 0;
        if (row == 0 && col == 0) {
          previous = 0;
        } else if (row == 0 && col > 0) {
          previous = grid[row][col - 1];
        } else if (row > 0 && col == 0) {
          previous = grid[row - 1][col];
        } else {
          previous = min(grid[row][col - 1], grid[row - 1][col]);
        }

        grid[row][col] = previous + grid[row][col];
      }
    }

    return grid[rowSize - 1][colSize - 1];
  }
};

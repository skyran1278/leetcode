#include <string>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 16 m 36 s
 * O(m + n)
 */
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rowSize = matrix.size() - 1;
    int colSize = matrix[0].size() - 1;

    int row = rowSize;
    int col = 0;
    while (row >= 0 && col <= colSize) {
      if (target < matrix[row][col]) {
        row--;
      } else if (target > matrix[row][col]) {
        col++;
      } else {
        return true;
      }
    }

    return false;
  }
};

int main() {
  Solution s;

  vector<vector<int>> s4 = {{-5}};
  s.searchMatrix(s4, -10);

  vector<vector<int>> s3 = {{-5}};
  s.searchMatrix(s3, -5);

  vector<vector<int>> s2 = {{1, 4, 7, 11, 15},
                            {2, 5, 8, 12, 19},
                            {3, 6, 9, 16, 22},
                            {10, 13, 14, 17, 24},
                            {18, 21, 23, 26, 30}};
  s.searchMatrix(s2, 20);

  vector<vector<int>> s1 = {{5, 6, 10, 14}, {6, 10, 13, 18}, {10, 13, 18, 19}};
  s.searchMatrix(s1, 14);
}

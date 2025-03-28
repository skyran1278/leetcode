#include <vector>

using namespace std;

/**
 * @brief 55 m 50 s
 * O(n)
 */
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int left = 0;
    int right = matrix[0].size();
    int top = 0;
    int bottom = matrix.size();
    int matrixSize = right * bottom;

    vector<int> result;
    result.reserve(matrixSize);

    int i = 0;
    int j = -1;
    while (result.size() < matrixSize) {
      top++;
      while (j < right - 1) {
        result.push_back(matrix[i][++j]);
      }

      right--;
      while (i < bottom - 1) {
        result.push_back(matrix[++i][j]);
      }

      bottom--;
      while (j > left && bottom >= top) {
        result.push_back(matrix[i][--j]);
      }

      left++;
      while (i > top && left <= right) {
        result.push_back(matrix[--i][j]);
      }
    }

    return result;
  }
};

int main() {
  Solution s;

  vector<vector<int>> s3 = {{1, 2}, {3, 4}};
  s.spiralOrder(s3);
  vector<vector<int>> s2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  s.spiralOrder(s2);
  vector<vector<int>> s1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  s.spiralOrder(s1);
}

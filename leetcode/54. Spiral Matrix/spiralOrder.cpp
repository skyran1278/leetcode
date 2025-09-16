#include <vector>

using namespace std;

/**
 * @brief 55 m 50 s
 * O(n)
 * O(1) extra (aside from the output list)
 */
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int left = 0;
    int right = (int)matrix[0].size();
    int top = 0;
    int bottom = (int)matrix.size();
    size_t matrixSize = (size_t)(right * bottom);

    vector<int> result;
    result.reserve(matrixSize);

    int i = 0;
    int j = -1;
    while (result.size() < matrixSize) {
      top++;
      while (j < right - 1) {
        result.push_back(matrix[(size_t)i][(size_t)++j]);
      }

      right--;
      while (i < bottom - 1) {
        result.push_back(matrix[(size_t)++i][(size_t)j]);
      }

      bottom--;
      while (j > left && bottom >= top) {
        result.push_back(matrix[(size_t)i][(size_t)--j]);
      }

      left++;
      while (i > top && left <= right) {
        result.push_back(matrix[(size_t)--i][(size_t)j]);
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

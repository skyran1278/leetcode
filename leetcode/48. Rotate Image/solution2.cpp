#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 3 m 52 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    for (size_t row = 0; row < matrix.size(); row++) {
      for (size_t col = row; col < matrix[0].size(); col++) {
        swap(matrix[row][col], matrix[col][row]);
      }
    }

    for (size_t row = 0; row < matrix.size(); row++) {
      reverse(matrix[row].begin(), matrix[row].end());
    }
  }
};

int main() {
  Solution s;

  vector<vector<int>> matrix2 = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  s.rotate(matrix2);
  vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  s.rotate(matrix1);
}

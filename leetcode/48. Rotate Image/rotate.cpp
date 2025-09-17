#include <vector>

using namespace std;

/**
 * @brief 43 m 9 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int layer = matrix.size();
    int last = layer - 1;

    for (size_t i = 0; i < layer / 2; i++) {
      int tmp = matrix[i][i];
      matrix[i][i] = matrix[last - i][i];
      matrix[last - i][i] = matrix[last - i][last - i];
      matrix[last - i][last - i] = matrix[i][last - i];
      matrix[i][last - i] = tmp;

      for (size_t j = i + 1; j < last - i; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[last - j][i];
        matrix[last - j][i] = matrix[last - i][last - j];
        matrix[last - i][last - j] = matrix[j][last - i];
        matrix[j][last - i] = tmp;
      }
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

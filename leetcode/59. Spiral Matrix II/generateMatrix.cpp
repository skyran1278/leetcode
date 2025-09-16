#include <vector>

using namespace std;

/**
 * @brief 22 m 40 s
 * @brief 20 m 48 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  // n = 3
  // [[1,2,3],[8,9,4],[7,6,5]]
  vector<vector<int>> generateMatrix(int n) {
    int left = 0;
    int right = n - 1;  // right = 2
    int top = 0;
    int bottom = n - 1;  // bottom = 2

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int row = 0;
    int col = -1;
    int i = 1;
    while (left <= right && top <= bottom) {
      while (col < right) {
        // col = 0
        // col = 1
        // col = 2
        // col = 1
        col++;

        // matrix = [1]
        // matrix = [1, 2]
        // matrix = [1, 2, 3]
        // matrix = [1, 2, 3], [8, 9, 4], [7, 6, 5]
        matrix[row][col] = i++;
      }

      // top = 1
      // top = 2
      top++;

      while (row < bottom) {
        // row = 1
        // row = 2
        row++;

        // matrix = [1, 2, 3], [0, 0, 4]
        // matrix = [1, 2, 3], [0, 0, 4], [0, 0, 5]
        matrix[row][col] = i++;
      }

      // right = 1
      right--;

      while (col > left) {
        // col = 1
        // col = 0
        col--;

        // matrix = [1, 2, 3], [0, 0, 4], [0, 6, 5]
        // matrix = [1, 2, 3], [0, 0, 4], [7, 6, 5]
        matrix[row][col] = i++;
      }

      // bottom = 1
      bottom--;

      while (row > top) {
        // row = 1
        row--;

        // matrix = [1, 2, 3], [8, 0, 4], [7, 6, 5]
        matrix[row][col] = i++;
      }

      // left = 1
      left++;
    }

    return matrix;
  }
};

int main() {
  Solution s;
  s.generateMatrix(3);
}

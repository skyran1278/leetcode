#include <vector>

using namespace std;

/**
 * @brief 22 m 40 s
 * O(n)
 */
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int total = n * n;

    int row = 0;
    int col = -1;
    int i = 1;
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    while (i <= total) {
      top++;
      while (col < right) {
        matrix[row][++col] = i++;
      }

      right--;
      while (row < bottom) {
        matrix[++row][col] = i++;
      }

      bottom--;
      while (col > left) {
        matrix[row][--col] = i++;
      }

      left++;
      while (row > top) {
        matrix[--row][col] = i++;
      }
    }

    return matrix;
  }
};

int main() {
  Solution s;
  s.generateMatrix(3);
}

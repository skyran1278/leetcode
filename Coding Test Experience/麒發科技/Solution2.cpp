#include <cassert>
#include <deque>
#include <vector>

using namespace std;

/**
 * @brief -- (editorial)
 * @brief 27m 13s (recall)
 * O(mn)
 * O(mn)
 */
class Solution {
 public:
  vector<vector<int>> maxpool2d(vector<vector<int>>& M, int kernel_size) {
    int m = static_cast<int>(M.size());
    int n = static_cast<int>(M[0].size());

    vector<vector<int>> rowMax(m, vector<int>(n - kernel_size + 1));
    for (int row = 0; row < m; ++row) {
      deque<int> monotonic;
      for (int col = 0; col < n; ++col) {
        if (!monotonic.empty() && monotonic.front() + kernel_size <= col) {
          monotonic.pop_front();
        }

        while (!monotonic.empty() && M[row][monotonic.back()] < M[row][col]) {
          monotonic.pop_back();
        }

        monotonic.push_back(col);

        if (col + 1 >= kernel_size) {
          rowMax[row][col + 1 - kernel_size] = M[row][monotonic.front()];
        }
      }
    }

    vector<vector<int>> result(m - kernel_size + 1,
                               vector<int>(n - kernel_size + 1));
    for (int col = 0; col < n - kernel_size + 1; ++col) {
      deque<int> monotonic;
      for (int row = 0; row < m; ++row) {
        if (!monotonic.empty() && monotonic.front() + kernel_size <= row) {
          monotonic.pop_front();
        }

        while (!monotonic.empty() &&
               rowMax[monotonic.back()][col] < rowMax[row][col]) {
          monotonic.pop_back();
        }

        monotonic.push_back(row);

        if (row + 1 >= kernel_size) {
          result[row + 1 - kernel_size][col] = rowMax[monotonic.front()][col];
        }
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<vector<int>> M = {
      {1, 3, -1, 2, 5, 3, 6, 7, 0, 1},
      {2, 10, 5, 1, 3, 4, 2, 8, 9, 0},
      {0, 1, 2, 23, 4, 5, 6, 7, 8, 9},
      {9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
  };
  vector<vector<int>> expected = {
      {10, 23, 23, 23, 6, 8, 9, 9},
      {10, 23, 23, 23, 6, 8, 9, 9},
  };
  assert(s.maxpool2d(M, 3) == expected);
  return 0;
}

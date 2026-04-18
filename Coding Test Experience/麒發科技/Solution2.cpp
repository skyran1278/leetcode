#include <deque>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief -- (editorial)
 * O(mn)
 * O(mn)
 */
class Solution {
 public:
  vector<vector<int>> maxpool2d(vector<vector<int>>& M, int kernel_size) {
    size_t m = M.size();
    size_t n = M[0].size();
    size_t k = static_cast<size_t>(kernel_size);
    if (m < k || n < k) return {};

    vector<vector<int>> H(m, vector<int>(n - k + 1));
    for (size_t row = 0; row < m; ++row) {
      deque<size_t> window;
      for (size_t col = 0; col < n; ++col) {
        if (!window.empty() && window.front() + k <= col) {
          window.pop_front();
        }
        while (!window.empty() && M[row][window.back()] <= M[row][col]) {
          window.pop_back();
        }
        window.push_back(col);
        if (col + 1 >= k) {
          H[row][col + 1 - k] = M[row][window.front()];
        }
      }
    }

    vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1));
    for (size_t col = 0; col < n - k + 1; ++col) {
      deque<size_t> window;
      for (size_t row = 0; row < m; ++row) {
        if (!window.empty() && window.front() + k <= row) {
          window.pop_front();
        }
        while (!window.empty() && H[window.back()][col] <= H[row][col]) {
          window.pop_back();
        }
        window.push_back(row);
        if (row + 1 >= k) {
          result[row + 1 - k][col] = H[window.front()][col];
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
  auto r = s.maxpool2d(M, 3);
  for (auto& row : r) {
    for (int v : row) cout << v << ' ';
    cout << '\n';
  }
  return 0;
}

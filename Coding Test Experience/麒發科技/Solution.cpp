#include <bitset>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief
 * O(mnk^2)
 * O(1)
 */
class Solution {
  vector<vector<int>> maxpool2d(vector<vector<int>>& M, int kernel_size) {
    vector<vector<int>> result{};
    int m = static_cast<int>(M.size());     // 4
    int n = static_cast<int>(M[0].size());  // 10
    for (int row = 0; row + kernel_size <= m; ++row) {
      vector<int> rowResult{};
      for (int col = 0; col + kernel_size <= n; ++col) {
        int maxValue = -__INT_MAX__ - 1;
        for (int dr = 0; dr < kernel_size; ++dr) {
          for (int dc = 0; dc < kernel_size; ++dc) {
            if (M[row + dr][col + dc] > maxValue)
              maxValue = M[row + dr][col + dc];  // 23
          }
        }
        rowResult.push_back(maxValue);  // {23, …}
      }
      result.push_back(rowResult);  // {{23, …}}
    }
    return result;
  }
};

#include <algorithm>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 11 m 13 s
 * @brief 6 m 12 s
 * O(m*n)
 * O(m+n)
 */
class Solution {
 public:
  // [
  //   [0,1,2,0],
  //   [3,4,5,2],
  //   [1,3,1,5]
  // ]
  void setZeroes(vector<vector<int>>& matrix) {
    vector<bool> rows(matrix.size());     // [0, 1, 1]
    vector<bool> cols(matrix[0].size());  // [0, 1, 1, 0]
    for (size_t row = 0; row < matrix.size(); row++) {
      for (size_t col = 0; col < matrix[row].size(); col++) {
        if (matrix[row][col] == 0) {
          rows[row] = true;
          cols[col] = true;
        }
      }
    }

    // [
    //   [0,0,0,0],
    //   [0,4,5,0],
    //   [0,3,1,0]
    // ]
    for (size_t row = 0; row < matrix.size(); row++) {
      for (size_t col = 0; col < matrix[row].size(); col++) {
        if (rows[row] || cols[col]) {
          matrix[row][col] = 0;
        }
      }
    }
  }
};

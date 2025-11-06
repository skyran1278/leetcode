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
 * @brief 13 m 52 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // [
  //  [1,2,3],
  //  [4,5,6],
  //  [7,8,9]
  // ],
  void rotate(vector<vector<int>>& matrix) {
    for (auto&& row : matrix) {
      reverse(row.begin(), row.end());
    }
    // [
    //  [3,2,1],
    //  [6,5,4],
    //  [9,8,7]
    // ],

    size_t n = matrix.size();  // 3
    for (size_t row = 0; row < n; row++) {
      for (size_t col = 0; col < n - row; col++) {
        swap(matrix[row][col], matrix[n - 1 - col][n - 1 - row]);
      }
    }
    // [
    //  [7,4,1],
    //  [8,5,2],
    //  [9,6,3]
    // ],
  }
};

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
 * @brief 3 m 51 s
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
    size_t n = matrix.size();  // 3
    for (size_t row = 0; row < n; row++) {
      for (size_t col = row; col < n; col++) {
        swap(matrix[row][col], matrix[col][row]);
      }
    }
    // [
    //  [1,4,7],
    //  [2,5,8],
    //  [3,6,9]
    // ],

    for (auto&& row : matrix) {
      reverse(row.begin(), row.end());
    }
    // [
    //  [7,4,1],
    //  [8,5,2],
    //  [9,6,3]
    // ],
  }
};

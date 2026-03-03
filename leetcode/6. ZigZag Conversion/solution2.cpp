#include <string>
#include <vector>

using namespace std;

/**
 * @brief 20m 14s
 * @brief 8m 40s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  // s = "PAYPALISHIRING", numRows = 3
  // P   A   H   N
  // A P L S I I G
  // Y   I   R
  // s = "AB", numRows = 1
  string convert(string s, size_t numRows) {
    if (numRows == 1 || numRows >= s.size()) return s;

    vector<string> rows(numRows);

    int row = 0;
    int reverse = -1;
    for (size_t i = 0; i < s.size(); i++) {
      rows[row].push_back(s[i]);

      if (row == 0 || row == numRows - 1) {
        reverse *= -1;
      }

      row += reverse;
    }

    string result;
    for (auto&& row : rows) {
      result += row;
    }

    return result;
  }
};

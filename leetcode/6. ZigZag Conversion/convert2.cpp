#include <string>
#include <vector>

using namespace std;

/**
 * @brief 20 m 14 s
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
    if (numRows == 1 || numRows >= s.size()) {
      return s;
    }

    vector<string> zigzag(numRows);

    size_t zigzagIndex = 0;
    size_t indexDirection = -1;
    for (size_t i = 0; i < s.size(); i++) {
      // zigzag = ["PAHN", "APLSIIG", "YIR"]
      zigzag[zigzagIndex].push_back(s[i]);

      if (zigzagIndex == 0 || zigzagIndex == numRows - 1) {
        indexDirection *= -1;
      }
      zigzagIndex += indexDirection;
    }

    string result;
    for (size_t i = 0; i < numRows; i++) {
      result += zigzag[i];
    }

    return result;
  }
};

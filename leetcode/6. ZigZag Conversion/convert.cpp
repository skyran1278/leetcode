#include <string>

using namespace std;

/**
 * @brief 37 m 46 s
 * O(n)
 */
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1 || s.length() < numRows) {
      return s;
    }

    string result;
    result.reserve(s.length());

    int cycleLen = 2 * numRows - 2;
    for (int row = 0; row < numRows; row++) {
      int len1 = cycleLen - 2 * row == 0 ? cycleLen : cycleLen - 2 * row;
      int len2 = 2 * row == 0 ? cycleLen : 2 * row;

      int j = row;
      while (j < s.length()) {
        result.push_back(s[j]);
        j += len1;
        if (j < s.length()) {
          result.push_back(s[j]);
          j += len2;
        }
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  s.convert("PAYPALISHIRING", 3);
  s.convert("A", 1);
}

#include <string>
#include <vector>

using namespace std;

/**
 * @brief 41 m 13 s
 * @brief 59 m 25 s
 * @brief 9 m 53 s
 * O(mn)
 * O(mn)
 */
class Solution {
 public:
  // s = "aab", p = "c*a*b"
  bool isMatch(string s, string p) {
    // [0,0,0,0,0,0]
    // [0,0,0,0,0,0]
    // [0,0,0,0,0,0]
    // [0,0,0,0,0,0]
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));

    // [1,0,0,0,0,0]
    // [0,0,0,0,0,0]
    // [0,0,0,0,0,0]
    // [0,0,0,0,0,0]
    dp[0][0] = true;

    // [1,0,1,0,1,0]
    // [0,0,0,0,0,0]
    // [0,0,0,0,0,0]
    // [0,0,0,0,0,0]
    for (size_t col = 2; col < p.size() + 1; col++) {
      if (p[col - 1] == '*') {
        dp[0][col] = dp[0][col - 2];
      }
    }

    //      c * a * b
    //   [1,0,1,0,1,0]
    // a [0,0,0,1,1,0]
    // a [0,0,0,0,1,0]
    // b [0,0,0,0,0,1]
    for (size_t row = 1; row < dp.size(); row++) {
      for (size_t col = 1; col < dp[row].size(); col++) {
        size_t sIndex = row - 1;
        size_t pIndex = col - 1;
        if (p[pIndex] == s[sIndex] || p[pIndex] == '.') {
          dp[row][col] = dp[row - 1][col - 1];
        } else if (p[pIndex] == '*') {
          dp[row][col] = dp[row][col - 2];  // 0
          if (p[pIndex - 1] == s[sIndex] || p[pIndex - 1] == '.') {
            dp[row][col] = dp[row][col] || dp[row - 1][col];  // 1 or more
          }
        }
      }
    }

    return dp[s.size()][p.size()];
  }
};

int main() {
  Solution s;

  s.isMatch("aa", "a*");
  s.isMatch("aa", "a");
}

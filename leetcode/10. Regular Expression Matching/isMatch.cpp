#include <string>
#include <vector>

using namespace std;

/**
 * @brief 看解答，沒做出來
 */
class Solution {
 public:
  bool isMatch(string s, string p) {
    int sLen = s.length();
    int pLen = p.length();

    vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1));

    // Empty string matches empty pattern
    dp[0][0] = true;

    for (size_t j = 2; j <= pLen; j++) {
      if (p[j - 1] == '*') {
        dp[0][j] = dp[0][j - 2];  // zero
      }
    }

    for (size_t i = 1; i <= sLen; i++) {
      for (size_t j = 1; j <= pLen; j++) {
        if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          dp[i][j] = dp[i][j - 2];  // zero
          if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
            dp[i][j] = dp[i - 1][j] || dp[i][j];  // one or more
          }
        }
      }
    }

    return dp[sLen][pLen];
  }
};

int main() {
  Solution s;

  s.isMatch("aa", "a*");
  s.isMatch("aa", "a");
}

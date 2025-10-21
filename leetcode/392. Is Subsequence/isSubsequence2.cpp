#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 我目前仍寫不出來動態規劃的程式，這是看官方解答的
 */
class Solution {
 public:
  // s = "abc", t = "ahbgdc"
  bool isSubsequence(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    /**
     *     a h b g d c
     *   0 0 0 0 0 0 0
     * a 0 1 1 1 1 1 1
     * b 0 0 0 2 2 2 2
     * c 0 0 0 0 0 0 3
     */
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (s[i - 1] == t[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = dp[i][j - 1];
      }
    }

    return dp[m][n] == m;
  }
};

int main() {
  Solution s;
  bool s1 = s.isSubsequence("abc", "ahbgdc");
  bool s2 = s.isSubsequence("axc", "ahbgdc");

  cout << s1 << std::endl;
}

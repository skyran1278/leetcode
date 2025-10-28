#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 11 m 20 s
 * O(mn)
 * O(mn)
 */
class Solution {
 public:
  // s = "abc", t = "ahbgdc"
  bool isSubsequence(string s, string t) {
    size_t sSize = s.size();
    size_t tSize = t.size();

    /**
     *     a h b g d c
     *   0 0 0 0 0 0 0
     * a 0 1 1 1 1 1 1
     * b 0 0 0 2 2 2 2
     * c 0 0 0 0 0 0 3
     */
    vector<vector<size_t>> dp(sSize + 1, vector<size_t>(tSize + 1));

    for (size_t row = 1; row <= sSize; row++) {
      for (size_t col = 1; col <= tSize; col++) {
        if (s[row - 1] == t[col - 1]) {
          dp[row][col] = dp[row - 1][col - 1] + 1;
        } else {
          dp[row][col] = dp[row][col - 1];
        }
      }
    }

    return dp[sSize][tSize] == sSize;
  }
};

int main() {
  Solution s;
  bool s1 = s.isSubsequence("abc", "ahbgdc");
  // bool s2 = s.isSubsequence("axc", "ahbgdc");

  cout << s1 << std::endl;
}

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
 * @brief
 * O(n^3)
 * O(n^2)
 */
class Solution {
 public:
  int countEval(string s, int result) {
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2)));

    for (size_t i = 0; i < n; i += 2) {
      if (s[i] == '1') {
        dp[i][i][1] = 1;
      } else {
        dp[i][i][0] = 1;
      }
    }

    for (int chunk = 2; chunk < n; chunk += 2) {
      for (int i = 0; i + chunk < n; i += 2) {
        for (int j = i + 1; j < i + chunk; j += 2) {
          int left0 = dp[i][j - 1][0];
          int left1 = dp[i][j - 1][1];
          int right0 = dp[j + 1][i + chunk][0];
          int right1 = dp[j + 1][i + chunk][1];

          if (s[j] == '&') {
            dp[i][i + chunk][0] += left0 * (right0 + right1) + left1 * right0;
            dp[i][i + chunk][1] += left1 * right1;
          } else if (s[j] == '|') {
            dp[i][i + chunk][0] += left0 * right0;
            dp[i][i + chunk][1] += left1 * (right0 + right1) + left0 * right1;
          } else if (s[j] == '^') {
            dp[i][i + chunk][0] += left0 * right0 + left1 * right1;
            dp[i][i + chunk][1] += left0 * right1 + left1 * right0;
          }
        }
      }
    }

    return dp[0][n - 1][result];
  }
};

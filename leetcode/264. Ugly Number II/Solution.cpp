#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 沒寫出來
 *
 */
class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> dp(n);
    dp[0] = 1;

    int index2 = 0;
    int index3 = 0;
    int index5 = 0;
    for (size_t i = 1; i < n; i++) {
      dp[i] = min(min(dp[index2] * 2, dp[index3] * 3), dp[index5] * 5);
      if (dp[i] == dp[index2] * 2) {
        index2++;
      }
      if (dp[i] == dp[index3] * 3) {
        index3++;
      }
      if (dp[i] == dp[index5] * 5) {
        index5++;
      }
    }

    return dp[n - 1];
  }
};

int main() {
  Solution s;
  s.nthUglyNumber(10);
}

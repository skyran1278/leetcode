#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 13 m 58 s
 * @brief 8 m 50 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> dp(n);

    size_t index2 = 0;
    size_t index3 = 0;
    size_t index5 = 0;

    dp[0] = 1;
    for (size_t i = 1; i < n; i++) {
      int next2 = dp[index2] * 2;
      int next3 = dp[index3] * 3;
      int next5 = dp[index5] * 5;

      dp[i] = min({next2, next3, next5});

      if (dp[i] == next2) {
        index2++;
      }
      if (dp[i] == next3) {
        index3++;
      }
      if (dp[i] == next5) {
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

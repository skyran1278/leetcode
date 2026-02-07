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
 * O(n^2)
 * O(n)
 */
class Solution {
 public:
  int pileBox(vector<vector<int>>& box) {
    sort(
        box.begin(), box.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    int n = box.size();
    vector<int> dp(n);
    int maxHeight = 0;

    for (int i = 0; i < n; i++) {
      dp[i] = box[i][2];

      for (int j = 0; j < i; j++) {
        if (box[j][0] < box[i][0] && box[j][1] < box[i][1] &&
            box[j][2] < box[i][2]) {
          dp[i] = max(dp[i], dp[j] + box[i][2]);
        }
      }

      if (dp[i] > maxHeight) maxHeight = dp[i];
    }

    return maxHeight;
  }
};

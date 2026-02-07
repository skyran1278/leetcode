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
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief
 * without sorting
 * O(n^2)
 * O(n)
 */
class Solution {
 private:
  // memo[i] stores the max height of a stack where box i is at the bottom
  vector<int> memo;

  // Helper function to find max height with 'bottomIndex' box at the bottom
  int dfs(const vector<vector<int>>& box, int bottomIndex) {
    // If already computed, return the stored value
    if (memo[bottomIndex] > 0) {
      return memo[bottomIndex];
    }

    int maxTopHeight = 0;

    // Try to find any box 'i' that can fit ON TOP of 'box[bottomIndex]'
    for (int i = 0; i < box.size(); ++i) {
      // Check strict inequality for all dimensions
      // We want to place box[i] ON TOP of box[bottomIndex]
      // So box[i] must be smaller than box[bottomIndex]
      if (box[i][0] < box[bottomIndex][0] && box[i][1] < box[bottomIndex][1] &&
          box[i][2] < box[bottomIndex][2]) {
        maxTopHeight = max(maxTopHeight, dfs(box, i));
      }
    }

    // The height of this stack is the height of the current bottom box
    // plus the max height of the stack that can go on top of it.
    memo[bottomIndex] = box[bottomIndex][2] + maxTopHeight;
    return memo[bottomIndex];
  }

 public:
  int pileBox(vector<vector<int>>& box) {
    int n = box.size();
    if (n == 0) return 0;

    memo.assign(n, 0);
    int globalMax = 0;

    // Any box can theoretically be the bottom of the stack
    for (int i = 0; i < n; ++i) {
      globalMax = max(globalMax, dfs(box, i));
    }

    return globalMax;
  }
};

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
 * @brief 19 m 23 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    vector<vector<int>> result = image;
    dfs(result, image, sr, sc, image[sr][sc], newColor);
    return result;
  }

  void dfs(vector<vector<int>>& result, vector<vector<int>>& image, int sr,
           int sc, int oldColor, int newColor) {
    if (image[sr][sc] != oldColor || result[sr][sc] == newColor) return;

    result[sr][sc] = newColor;

    if (sr - 1 >= 0)
      dfs(result, image, sr - 1, sc, oldColor, newColor);  // (0, 1)
    if (sc - 1 >= 0)
      dfs(result, image, sr, sc - 1, oldColor, newColor);  // (1, 0)
    if (sr + 1 < image.size())
      dfs(result, image, sr + 1, sc, oldColor, newColor);  // (2, 1)
    if (sc + 1 < image[0].size())
      dfs(result, image, sr, sc + 1, oldColor, newColor);  // (1, 2)
  }
};

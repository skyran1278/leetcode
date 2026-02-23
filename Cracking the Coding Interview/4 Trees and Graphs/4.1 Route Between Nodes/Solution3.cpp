#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 13 m 15 s
 * O(V + E)
 * O(V)
 */
class Solution {
 public:
  bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start,
                             int target) {
    vector<vector<int>> tree(n);

    for (auto&& pair : graph) {
      tree[pair[0]].push_back(pair[1]);
    }

    vector<bool> visit(n);
    return dfs(tree, visit, start, target);
  }

  bool dfs(vector<vector<int>>& tree, vector<bool>& visit, int start,
           int target) {
    if (start == target) return true;

    for (auto&& next : tree[start]) {
      if (visit[next]) continue;

      visit[next] = true;
      if (dfs(tree, visit, next, target)) return true;
    }

    return false;
  }
};

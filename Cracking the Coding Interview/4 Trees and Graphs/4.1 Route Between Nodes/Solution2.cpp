#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 11 m 6 s
 * @brief 15 m 7 s
 * O(V + E)
 * O(V)
 */
class Solution {
 public:
  bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start,
                             int target) {
    vector<vector<int>> tree(n);

    for (auto&& edge : graph) {
      tree[edge[0]].push_back(edge[1]);
    }

    vector<bool> visited(n);
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
      int count = q.size();
      for (size_t i = 0; i < count; i++) {
        int val = q.front();
        q.pop();

        if (val == target) return true;

        for (auto&& next : tree[val]) {
          if (!visited[next]) {
            visited[next] = true;
            q.push(next);
          }
        }
      }
    }

    return false;
  }
};

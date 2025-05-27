#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 38 m 9 s
 *
 */
class Solution {
 public:
  bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start,
                             int target) {
    if (start == target) return true;

    unordered_set<int> startVisited;
    unordered_set<int> targetVisited;
    queue<int> startQueue;
    queue<int> targetQueue;

    startQueue.push(start);
    startVisited.insert(start);

    targetQueue.push(target);
    targetVisited.insert(target);

    while (!startQueue.empty() && !targetQueue.empty()) {
      int startNode = startQueue.front();
      startQueue.pop();

      int targetNode = targetQueue.front();
      targetQueue.pop();

      for (auto&& edge : graph) {
        int first = edge[0];
        int second = edge[1];

        if (startVisited.find(second) == startVisited.end() &&
            first == startNode) {
          if (targetVisited.count(second)) {
            return true;
          }

          startQueue.push(second);
          startVisited.insert(second);
        }

        if (targetVisited.find(first) == targetVisited.end() &&
            second == targetNode) {
          if (startVisited.find(first) != startVisited.end()) {
            return true;
          }

          targetQueue.push(first);
          targetVisited.insert(first);
        }
      }
    }

    return false;
  }
};

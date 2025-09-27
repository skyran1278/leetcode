#include <queue>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 53 m 18 s
 * @brief 15 m 57 s
 * O(V + E) (courses + prerequisites)
 * O(V + E) (adjacency list + recursion/queue)
 */
class Solution {
 public:
  // numCourses = 2, prerequisites = [[1,0]]
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> inDegree(numCourses, 0);
    vector<vector<int>> graph(numCourses);  // adjacency list

    for (auto&& pre : prerequisites) {
      graph[pre[1]].push_back(pre[0]);  // graph = 0: [1]
      inDegree[pre[0]]++;               // inDegree = [0, 1]
    }

    queue<size_t> q;
    for (size_t i = 0; i < numCourses; i++) {
      if (inDegree[i] == 0) {
        q.push(i);  // q = 0
      }
    }

    int completedCourse = 0;
    while (!q.empty()) {
      size_t course = q.front();
      q.pop();
      completedCourse++;

      for (auto&& nextCourse : graph[course]) {
        if (--inDegree[nextCourse] == 0) {
          q.push(nextCourse);
        }
      }
    }

    return completedCourse == numCourses;
  }
};

int main() {
  Solution s;

  int s11 = 2;
  vector<vector<int>> s12 = {{1, 0}};
  s.canFinish(s11, s12);
}

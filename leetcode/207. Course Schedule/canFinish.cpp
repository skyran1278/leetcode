#include <queue>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 53 m 18 s
 * O(m + n)
 */
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);  // adjacency list
    vector<int> inDegree(numCourses, 0);

    for (auto&& pre : prerequisites) {
      graph[pre[1]].push_back(pre[0]);
      inDegree[pre[0]]++;
    }

    queue<int> q;
    for (size_t i = 0; i < inDegree.size(); i++) {
      if (inDegree[i] == 0) {
        q.push(i);
      }
    }

    int completedCourse = 0;
    while (!q.empty()) {
      int course = q.front();
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

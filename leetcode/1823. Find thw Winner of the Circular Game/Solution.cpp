#include <queue>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 36 m 6 s
 * @brief 12 m 52 s
 * @brief 5 m 27 s
 * O(n × k)
 * O(n)
 */
class Solution {
 public:
  int findTheWinner(int n, int k) {
    queue<int> q;
    for (size_t i = 1; i <= n; i++) {
      q.push(i);
    }

    while (q.size() > 1) {
      for (size_t i = 1; i < k; i++) {
        q.push(q.front());
        q.pop();
      }
      q.pop();
    }

    return q.front();
  }
};

int main() {
  Solution s;
  s.findTheWinner(5, 2);
}

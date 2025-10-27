#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 15 m 18 s
 * O(n)
 * O(n)
 * maximum value on the left is ≤ the minimum value on the right
 */
class Solution {
 public:
  // arr = [0,1,0,1,0]
  int maxChunksToSorted(vector<int>& arr) {
    stack<int> s;

    for (auto&& num : arr) {
      if (s.empty() || num >= s.top()) {
        s.push(num);  // s = [0, 1, 1]
      } else {
        int top = s.top();
        while (!s.empty() && s.top() > num) {
          s.pop();
        }
        s.push(top);  // s = [0, 1]
      }
    }

    return s.size();
  }
};

int main() {
  Solution s;

  vector<int> s1 = {2, 1, 3, 4, 4};
  s.maxChunksToSorted(s1);
}

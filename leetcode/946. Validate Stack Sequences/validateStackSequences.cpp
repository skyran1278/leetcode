#include <stack>
#include <vector>

using namespace std;

/**
 * @brief 29 m 20 s
 * @brief 17 m 49 s
 * @brief 6 m 55 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  // pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
  // pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> s;

    size_t length = pushed.size();
    size_t pushIndex = 0;
    size_t popIndex = 0;

    while (pushIndex < length) {
      s.push(pushed[pushIndex++]);

      while (!s.empty() && s.top() == popped[popIndex]) {
        s.pop();

        popIndex++;
      }
    }

    return s.empty();
  }
};

int main() {
  Solution s;
  vector<int> pushed = {1, 2, 3, 4, 5};
  vector<int> popped = {4, 3, 5, 1, 2};
  s.validateStackSequences(pushed, popped);
}

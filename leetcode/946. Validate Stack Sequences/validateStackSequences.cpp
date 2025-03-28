#include <stack>
#include <vector>

using namespace std;

/**
 * @brief 29 m 20 s
 * O(n)
 */
class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stack;

    size_t i = 0;
    size_t j = 0;
    while (i < pushed.size()) {
      stack.push(pushed[i++]);
      while (!stack.empty() && stack.top() == popped[j]) {
        stack.pop();
        j++;
      }
    }

    return stack.empty();
  }
};

int main() {
  Solution s;
  vector<int> pushed = {1, 2, 3, 4, 5};
  vector<int> popped = {4, 3, 5, 1, 2};
  s.validateStackSequences(pushed, popped);
}

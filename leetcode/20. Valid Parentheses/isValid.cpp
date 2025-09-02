#include <stack>
#include <string>

using namespace std;

/**
 * @brief 10 m 54 s
 * @brief 12 m 47 s
 * O(n)
 */
class Solution {
 public:
  // s = "()[]{}"
  bool isValid(string s) {
    stack<char> charStack;

    for (auto &&c : s) {
      if (c == '(') {
        // 1. charStack = [')']
        charStack.push(')');
      } else if (c == '[') {
        charStack.push(']');
      } else if (c == '{') {
        charStack.push('}');
      } else {
        if (charStack.empty()) {
          return false;
        }

        // 2. charStack = []
        char prevChar = charStack.top();
        charStack.pop();

        if (prevChar != c) {
          return false;
        }
      }
    }

    return charStack.empty();
  }
};

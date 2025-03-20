#include <stack>
#include <string>

/**
 * @brief O(n)
 * 10 m 54 s
 */
class Solution {
 public:
  bool isValid(std::string s) {
    std::stack<char> charStack;

    for (auto &&c : s) {
      switch (c) {
        case '(':
        case '{':
        case '[':
          charStack.push(c);
          break;
        case ')':
          if (charStack.empty() || charStack.top() != '(') {
            return false;
          }
          charStack.pop();
          break;
        case '}':
          if (charStack.empty() || charStack.top() != '{') {
            return false;
          }
          charStack.pop();
          break;
        case ']':
          if (charStack.empty() || charStack.top() != '[') {
            return false;
          }
          charStack.pop();
          break;

        default:
          break;
      }
    }

    return charStack.empty();
  }
};

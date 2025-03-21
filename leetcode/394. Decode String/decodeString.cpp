#include <deque>
#include <iostream>
#include <stack>
#include <string>

/**
 * @brief O(n) n == decoded string length
 * 59 m 56 s
 */
class Solution {
 public:
  std::string decodeString(std::string s) {
    std::stack<std::string> strStack;
    std::stack<int> numStack;
    std::string current;
    int k = 0;

    for (auto&& c : s) {
      if (isdigit(c)) {
        k = k * 10 + (c - '0');
      } else if (c == '[') {
        numStack.push(k);
        strStack.push(current);
        current.clear();
        k = 0;
      } else if (c == ']') {
        std::string decoded = strStack.top();
        strStack.pop();

        int k = numStack.top();
        numStack.pop();

        for (size_t i = 0; i < k; i++) {
          decoded += current;
        }
        current = decoded;
      } else {
        current += c;
      }
    }

    return current;
  }
};

int main() {
  Solution* s = new Solution();
  std::string decode = s->decodeString("3[a]2[bc]");
  std::string decode2 = s->decodeString("100[leetcode]");
  std::string decode3 = s->decodeString("3[a2[c]]");

  std::cout << decode << std::endl;
}

#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * @brief 59 m 56 s
 * @brief 14 m 4 s
 *
 * O(n) n == decoded string length
 * O(n)
 */
class Solution {
 public:
  // s = "3[a2[c]]"
  // s = "3[a]2[bc]"
  string decodeString(string s) {
    stack<int> countStack;
    stack<string> decodedStack;
    string current = "";
    string k = "";

    for (auto&& c : s) {
      if (isdigit(c)) {
        k += c;
      } else if (c == '[') {
        // countStack = [3]
        // countStack = [3, 2]
        countStack.push(stoi(k));
        k.clear();

        // currentStack = [""]
        // currentStack = ["", "a"]
        decodedStack.push(current);
        current.clear();
      } else if (c == ']') {
        // decode = "a"
        // decode = ""
        string decoded = decodedStack.top();
        decodedStack.pop();

        // k = 2
        // k = 3
        int count = countStack.top();
        countStack.pop();

        for (size_t i = 0; i < count; i++) {
          decoded += current;
        }

        // current = "acc"
        // current = "accaccacc"
        current = decoded;
      } else {
        // current = "a"
        // current = "c"
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

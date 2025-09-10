#include <sstream>
#include <stack>
#include <string>

using namespace std;

/**
 * @brief 53 m 4 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // s = "  hello world  "
  string reverseWords(string s) {
    stringstream ss(s);
    stack<string> sStack;
    string word;
    while (ss >> word) {
      sStack.push(word);
    }

    string reverse;
    while (!sStack.empty()) {
      reverse.append(sStack.top() + ' ');
      sStack.pop();
    }

    return reverse.substr(0, reverse.length() - 1);
  }
};

int main() {
  Solution s;
  string s1 = s.reverseWords("the sky is blue");
}

#include <sstream>
#include <stack>
#include <string>

using namespace std;

/**
 * @brief
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // s = "  hello world  "
  string reverseWords(string s) {
    size_t left = s.length();
    size_t right = s.length();

    string reverse;
    while (left > 0) {
      // skip trailing spaces
      while (left > 0 && s[left - 1] == ' ') {
        left--;
      }
      right = left;

      // find the start of the word
      while (left > 0 && s[left - 1] != ' ') {
        left--;
      }

      // append the word if found
      if (right > left) {
        // reverse = "world"
        // reverse = "world hello"
        if (!reverse.empty()) reverse += " ";  // add space before appending
        reverse += s.substr(left + 1, right - left) + " ";
      }
    }
    return reverse;
  }
};

int main() {
  Solution s;
  string s1 = s.reverseWords("the sky is blue");
}

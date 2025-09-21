#include <algorithm>
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
    // s = "  dlrow olleh  "
    reverse(s.begin(), s.end());

    size_t idx = 0;
    size_t left = 0;

    while (left < s.size()) {
      if (s[left] != ' ') {
        // left = 2
        if (idx != 0) {
          // s = "world w olleh  "
          s[idx++] = ' ';
        }

        size_t right = left;  // right = 8
        while (right < s.size() && s[right] != ' ') {
          s[idx++] = s[right++];
        }
        // right = 13
        // idx = 11
        // s = "world ollehh  "

        reverse(s.begin() + idx - (right - left), s.begin() + idx);
        // s = "worldow olleh  "

        // left = 7
        left = right;
      }

      left++;
    }

    s.erase(s.begin() + idx, s.end());

    return s;
  }
};

int main() {
  Solution s;
  string s1 = s.reverseWords("the sky is blue");
}

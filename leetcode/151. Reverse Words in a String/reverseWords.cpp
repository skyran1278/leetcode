#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * @brief 28 m 53 s
 * O(n)
 */
class Solution {
 public:
  string reverseWords(string s) {
    string reverseS = "";

    size_t i = 0;
    while (i < s.length()) {
      if (s[i] != ' ') {
        size_t j = i + 1;
        while (s[j] != ' ' && j < s.length()) {
          j++;
        }
        reverseS = s.substr(i, j - i) + " " + reverseS;
        i = j;
      }
      i++;
    }

    if (!reverseS.empty()) {
      reverseS.pop_back();
    }

    return reverseS;
  }
};

int main() {
  Solution s;
  string s1 = s.reverseWords("the sky is blue");

  cout << s1 << endl;
}

#include <string>

using namespace std;

/**
 * @brief 33 m 8 s
 * @brief 4 m 33 s
 * O(t)
 * O(1)
 */
class Solution {
 public:
  // s = "abc", t = "ahbgdc"
  bool isSubsequence(string s, string t) {
    int sIndex = 0;
    int tIndex = 0;
    while (sIndex < s.length() && tIndex < t.length()) {
      char sChar = s[sIndex];
      char tChar = t[tIndex];

      if (sChar == tChar) {
        // sIndex = 1
        // sIndex = 2
        // sIndex = 3
        sIndex++;
      }

      // tIndex = 1
      // tIndex = 2
      // tIndex = 3
      // tIndex = 4
      // tIndex = 5
      // tIndex = 6
      tIndex++;
    }

    return sIndex == s.length();
  }
};

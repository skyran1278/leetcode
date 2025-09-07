#include <array>
#include <string>

using namespace std;

/**
 * @brief 5 m 56 s
 * O(n)
 */
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }

    array<int, 26> alphabet;

    for (size_t i = 0; i < s.size(); i++) {
      char c = s[i];
      alphabet[c - 'a'] += 1;
    }

    for (size_t i = 0; i < t.size(); i++) {
      char c = t[i];
      alphabet[c - 'a'] -= 1;

      if (alphabet[c - 'a'] < 0) {
        return false;
      }
    }

    return true;
  }
};

#include <string>
#include <unordered_map>

using namespace std;

/**
 * @brief 22 m 59 s
 * O(n)
 */
class Solution {
 public:
  int longestPalindrome(string s) {
    // http://sticksandstones.kstrom.com/appen.html
    // A: 065
    // Z: 090
    // a: 097
    // z: 122
    int palindrome[58] = {};

    for (size_t i = 0; i < s.length(); i++) {
      palindrome[s[i] - 'A']++;
    }

    int longest = 0;
    bool hasOdd = false;
    for (size_t i = 0; i < 58; i++) {
      int length = palindrome[i];
      if (length % 2 != 0) {
        longest += length - 1;
        hasOdd = true;
      } else {
        longest += length;
      }
    }

    if (hasOdd) longest += 1;

    return longest;
  }
};

int main() {
  Solution s;
  s.longestPalindrome("abccccdd");
  s.longestPalindrome(
      "zeusnilemacaronimaisanitratetartinasiaminoracamelinsuez");
}

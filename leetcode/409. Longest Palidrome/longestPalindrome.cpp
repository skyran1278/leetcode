#include <array>
#include <string>

using namespace std;

/**
 * @brief 22 m 59 s
 * O(n)
 */
class Solution {
 public:
  // s = "abccccdd"
  // s = "bananas"
  int longestPalindrome(string s) {
    // http://sticksandstones.kstrom.com/appen.html
    // A: 065
    // Z: 090
    // a: 097
    // z: 122
    array<int, 256> countList = {};

    for (auto &&c : s) {
      countList[c]++;
    }

    int length = 0;
    bool hasOdd = false;
    for (auto &&count : countList) {
      length += count;
      if (count % 2 == 1) {
        if (hasOdd) {
          length--;
        } else {
          hasOdd = true;
        }
      }
    }

    return length;
  }
};

int main() {
  Solution s;
  s.longestPalindrome("abccccdd");
  s.longestPalindrome(
      "zeusnilemacaronimaisanitratetartinasiaminoracamelinsuez");
}

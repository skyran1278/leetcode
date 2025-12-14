#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 24 m 27 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  bool isNumber(string s) {
    bool seenNumber = false;
    bool seenE = false;
    bool seenDot = false;

    for (size_t i = 0; i < s.size(); i++) {
      char c = s[i];

      if (isdigit(c)) {
        seenNumber = true;
      } else if (c == '-' || c == '+') {
        if (i > 0 && !(s[i - 1] == 'e' || s[i - 1] == 'E')) return false;
      } else if (c == 'e' || c == 'E') {
        if (seenE || !seenNumber) return false;

        seenE = true;
        seenNumber = false;
      } else if (c == '.') {
        if (seenDot || seenE) return false;
        seenDot = true;
      } else {
        return false;
      }
    }

    return seenNumber;
  }
};

int main() {
  Solution s;
  s.isNumber("e9");
}

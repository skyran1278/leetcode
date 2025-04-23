#include <array>
#include <climits>
#include <string>

using namespace std;

/**
 * @brief 28 m 28 s
 * O(n)
 */
class Solution {
 public:
  int firstUniqChar(string s) {
    int alphabet[26] = {};
    for (size_t i = 0; i < s.size(); i++) {
      alphabet[s[i] - 'a']++;
    }
    for (size_t i = 0; i < s.size(); i++) {
      if (alphabet[s[i] - 'a'] == 1) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  s.firstUniqChar("leetcode");
}

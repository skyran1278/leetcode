#include <array>
#include <string>

using namespace std;

/**
 * @brief 28 m 28 s
 * @brief 24 m 10 s
 * @brief 12 m 27 s
 * @brief 2 m 23 s
 * O(n)
 */
class Solution {
 public:
  int firstUniqChar(string s) {
    array<int, 26> alphabet;

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

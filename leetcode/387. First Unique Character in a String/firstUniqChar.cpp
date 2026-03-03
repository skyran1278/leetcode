#include <array>
#include <string>

using namespace std;

/**
 * @brief 28m 28s
 * @brief 24m 10s
 * @brief 12m 27s
 * @brief 2m 23s
 * @brief 2m 18s
 * @brief 2m 15s
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

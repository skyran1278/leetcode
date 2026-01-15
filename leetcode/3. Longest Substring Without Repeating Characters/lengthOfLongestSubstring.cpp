#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * @brief 34 m 0 s
 * @brief 20 m 55 s
 * @brief 20 m 42 s
 * @brief 15 m 26 s
 * @brief 8 m 47 s
 * @brief 11 m 46 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // s = "pwwkew"
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, size_t> map;
    size_t longestLength = 0;
    size_t left = 0;
    size_t right = 0;

    while (right < s.length()) {
      // 1. c = p
      // 2. c = w
      // 3. c = w
      // 4. c = k
      // 5. c = e
      // 6. c = w
      char c = s[right];

      if (map.count(c) > 0 && map[c] >= left) {
        // 3. left = 2
        // 6. left = 3
        left = map[c] + 1;
      }

      // 1. map: p = 0
      // 2. map: p = 0, w: 1
      // 3. map: p = 0, w: 2
      // 4. map: p = 0, w: 2, k: 3
      // 5. map: p = 0, w: 2, k: 3, e: 4
      // 6. map: p = 0, w: 5, k: 3, e: 4
      map[c] = right;

      size_t length = right - left + 1;
      if (length > longestLength) {
        // 1. longestLength = 1
        // 2. longestLength = 2
        // 5. longestLength = 3
        longestLength = length;
      }
      // 1. right = 1
      // 2. right = 2
      // 3. right = 3
      // 4. right = 4
      // 5. right = 5
      right++;
    }

    return (int)longestLength;
  }
};

int main() {
  Solution s;
  int s1 = s.lengthOfLongestSubstring("abcabcbb");
  int s2 = s.lengthOfLongestSubstring("abba");
  int s3 = s.lengthOfLongestSubstring("pwwkew");
  int s4 = s.lengthOfLongestSubstring("tmmzuxt");
  cout << s3 << endl;
}

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * @brief 34 m 0 s
 * O(n)
 */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, size_t> sMap;

    size_t i = 0;
    size_t j = 0;
    int longest = 0;
    while (j < s.length()) {
      char c = s[j];
      if (sMap.count(c) > 0) {
        i = max(sMap[c] + 1, i);
      }
      sMap[c] = j;

      int current = j - i + 1;
      longest = max(current, longest);
      j++;
    }
    return longest;
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

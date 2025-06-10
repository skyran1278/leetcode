#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 2 m 22 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  bool CheckPermutation(string s1, string s2) {
    if (s1.length() != s2.length()) {
      return false;
    }

    unordered_map<char, int> charMap;

    for (auto &&c : s1) {
      if (!charMap.count(c)) {
        charMap[c] = 0;
      }
      charMap[c] += 1;
    }

    for (auto &&c : s2) {
      if (charMap.count(c)) {
        charMap[c] -= 1;
      }

      if (!charMap.count(c) || charMap[c] < 0) {
        return false;
      }
    }

    return true;
  }
};

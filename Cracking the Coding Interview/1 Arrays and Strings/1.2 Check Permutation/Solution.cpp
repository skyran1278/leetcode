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
 * @brief 2 m 42 s
 * @brief 4 m 1 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  bool CheckPermutation(string s1, string s2) {
    if (s1.size() != s2.size()) return false;

    unordered_map<char, int> map;
    for (auto&& c : s1) {
      map[c]++;
    }
    for (auto&& c : s2) {
      if (map[c]-- == 0) {
        return false;
      }
    }

    return true;
  }
};

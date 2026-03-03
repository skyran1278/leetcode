#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 2m 22s
 * @brief 2m 42s
 * @brief 4m 1s
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

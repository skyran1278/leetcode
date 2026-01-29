#include <algorithm>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 5 m 32 s
 * @brief 3 m 58 s
 * O(n) Substring search is linear (in practice, near O(n))
 * O(n) For concatenation of s1 + s1
 */
class Solution {
 public:
  bool isFlipedString(string s1, string s2) {
    return s1.size() == s2.size() && (s1 + s1).find(s2) != string::npos;
  }
};

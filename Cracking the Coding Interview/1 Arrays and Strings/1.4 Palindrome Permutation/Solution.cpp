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
 * @brief 6m 19s
 * @brief 4m 13s
 * O(n)
 * O(Σ)
 */
class Solution {
 public:
  bool canPermutePalindrome(string s) {
    unordered_map<char, int> map;
    for (auto&& c : s) {
      map[c]++;
    }

    int oddCount = 0;
    for (auto&& [c, count] : map) {
      if (count % 2 == 1) oddCount++;
    }

    return oddCount <= 1;
  }
};

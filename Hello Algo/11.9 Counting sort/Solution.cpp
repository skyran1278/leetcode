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
 * @brief 7 m 49 s
 * @brief 16 m 3 s
 * O(n + k)
 * O(n + k)
 * stable
 */
class Solution {
 public:
  string countSort(string s) {
    size_t n = 26;
    vector<int> count(n, 0);

    for (auto&& c : s) {
      count[c - 'a']++;
    }

    for (size_t i = 1; i < n; i++) {
      count[i] += count[i - 1];
    }

    string result = s;
    for (int i = s.size() - 1; i >= 0; i--) {
      result[--count[s[i] - 'a']] = s[i];
    }

    return result;
  }
};

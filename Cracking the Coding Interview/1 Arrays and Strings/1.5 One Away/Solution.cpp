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
 * @brief 28 m 25 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // first = "pale", second = "ple"
  bool oneEditAway(string first, string second) {
    if (first.size() < second.size()) return oneEditAway(second, first);

    switch (first.size() - second.size()) {
      case 0:
        return isReplaceOnce(first, second);
      case 1:
        return isInsertOnce(first, second);
      default:
        return false;
    }
  }

  // first = "a", second = ""
  // first = ""bleacher"", second = "teacher"
  bool isInsertOnce(string& first, string& second) {
    size_t i = 0;
    size_t j = 0;

    while (i < first.size() && j < second.size()) {
      if (first[i] == second[j]) {
        j++;
      }
      i++;
    }

    return j == second.size();
  }

  bool isReplaceOnce(string& first, string& second) {
    int unequalCount = 0;
    for (size_t i = 0; i < first.size(); i++) {
      if (first[i] != second[i]) {
        unequalCount++;
      }
    }

    return unequalCount <= 1;
  }
};

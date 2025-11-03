#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 1 m 8 s
 *
 */
class Solution {
 public:
  bool isUnique(string astr) {
    sort(astr.begin(), astr.end());

    for (size_t i = 1; i < astr.size(); i++) {
      if (astr[i - 1] == astr[i]) {
        return false;
      }
    }

    return true;
  }
};

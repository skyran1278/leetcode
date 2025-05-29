#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 1 m 19 s
 *
 */
class Solution {
 public:
  bool isUnique(string astr) {
    int size = astr.length();
    for (size_t i = 0; i < size; i++) {
      char c = astr[i];
      for (size_t j = 0; j < i; j++) {
        if (astr[j] == c) {
          return false;
        }
      }
    }

    return true;
  }
};

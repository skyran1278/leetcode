#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 4 m 25 s
 * @brief 8 m 10 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  string replaceSpaces(string S, int length) {
    string result;
    for (size_t i = 0; i < length; i++) {
      if (S[i] == ' ') {
        result += "%20";
      } else {
        result += S[i];
      }
    }

    return result;
  }
};

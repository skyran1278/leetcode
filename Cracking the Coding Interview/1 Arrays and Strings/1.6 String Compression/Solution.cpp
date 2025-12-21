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
 * @brief 11 m 10 s
 * @brief 7 m 31 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  // "abbccd"
  string compressString(string S) {
    string result;
    result.reserve(S.size());

    int count = 1;
    for (size_t i = 0; i < S.size(); i++) {
      if (i + 1 < S.size() && S[i] == S[i + 1]) {
        count++;
      } else {
        result += S[i] + to_string(count);  // a1b2c2d1
        count = 1;
      }
    }

    return result.size() < S.size() ? result : S;
  }
};

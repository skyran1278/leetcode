#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 27 m 27 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // "Mr John Smith    ", 13
  string replaceSpaces(string S, int length) {
    int newLength = length;
    for (size_t i = 0; i < length; i++) {
      if (S[i] == ' ') newLength += 2;
    }

    int i = length - 1;     // 12
    int j = newLength - 1;  // 16
    while (i >= 0) {
      if (S[i] == ' ') {
        // "Mr John S%20Smith"
        // "Mr%20John%20Smith"
        S[j--] = '0';
        S[j--] = '2';
        S[j--] = '%';
      } else {
        // "Mr John SmitSmith"
        // "Mr JoJohn%20Smith"
        S[j--] = S[i];
      }
      i--;
    }

    return S.substr(j + 1, newLength);
  }
};

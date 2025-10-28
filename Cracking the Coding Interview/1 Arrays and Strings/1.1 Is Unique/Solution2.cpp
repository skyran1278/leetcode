#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * bit
 */
class Solution {
 public:
  bool isUnique(string astr) {
    int size = astr.length();

    int bitMap = 0;
    for (size_t i = 0; i < size; i++) {
      int cBit = astr[i] - 'a';
      if ((bitMap >> cBit & 1) == 1) return false;
      bitMap |= 1 << cBit;
    }

    return true;
  }
};

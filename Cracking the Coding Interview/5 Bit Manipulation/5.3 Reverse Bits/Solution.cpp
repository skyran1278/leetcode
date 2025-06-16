#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 23 m 16 s
 * get bit
 * O(1)
 * O(1)
 */
class Solution {
 public:
  int reverseBits(int num) {
    int maxLen = 0;
    int currOnes = 0;
    int prevOnes = 0;

    for (size_t i = 0; i < 32; i++) {
      bool bit = num & (1 << i);

      if (bit) {
        currOnes++;
      } else {
        prevOnes = currOnes;
        currOnes = 0;
      }

      maxLen = max(maxLen, prevOnes + currOnes + 1);
    }

    return min(maxLen, 32);
  }
};

int main() {
  Solution s;
  s.reverseBits(1775);
}

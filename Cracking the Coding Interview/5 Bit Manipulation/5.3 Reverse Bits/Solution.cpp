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
 * can do it in a reverse way, but not intuitive
 * O(1)
 * O(1)
 */
class Solution {
 public:
  int reverseBits(int num) {
    int maxLength = 0;
    int currentLength = 0;
    int previousLength = 0;
    for (size_t i = 0; i < 32; i++) {
      bool is1 = (1 << i) & num;
      if (is1) {
        currentLength++;
      } else {
        previousLength = currentLength;
        currentLength = 0;
      }

      maxLength = max(maxLength, currentLength + previousLength + 1);
    }

    return min(maxLength, 32);
  }
};

int main() {
  Solution s;
  s.reverseBits(1775);
}

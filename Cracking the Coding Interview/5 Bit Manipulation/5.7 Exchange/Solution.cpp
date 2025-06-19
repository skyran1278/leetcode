#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 19 m 48 s
 * What are the 32-bit values where all even or all odd bit positions are set to
 * 1?
 * O(1)
 * O(1)
 */
class Solution {
 public:
  int exchangeBits(int num) {
    int odd = num << 1;
    int even = num >> 1;
    int result = 0;
    for (size_t i = 0; i < 32; i += 2) {
      result |= even & 1 << i;
      result |= odd & 1 << i + 1;
    }

    return result;
  }
};

int main() {
  Solution s;
  s.exchangeBits(1);
}

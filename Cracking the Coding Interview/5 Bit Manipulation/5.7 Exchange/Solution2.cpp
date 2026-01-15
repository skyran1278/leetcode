#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 9 m 32 s
 * @brief 2 m 30 s
 * O(1)
 * O(1)
 */
class Solution {
 public:
  int exchangeBits(int num) {
    return (num >> 1 & 0x55555555) | (num << 1 & 0xaaaaaaaa);
  }
};

int main() {
  Solution s;
  s.exchangeBits(1);
}

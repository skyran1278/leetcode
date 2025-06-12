#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 9 m 21 s
 * O(1)
 * O(1)
 */
class Solution {
 public:
  int insertBits(int N, int M, int i, int j) {
    for (size_t index = i; index <= j; index++) {
      int mask = ~(1 << index);
      N = N & mask;
    }

    return N | M << i;
  }
};

int main() {
  Solution s;
  s.insertBits(2032243561, 10, 24, 29);
}

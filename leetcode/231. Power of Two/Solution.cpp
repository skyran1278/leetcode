#include <cmath>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 7m 26s
 * @brief 3m 20s
 * @brief 2m 48s
 * O(1)
 * O(1)
 * bit
 */
class Solution {
 public:
  bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
};

#include <cmath>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 7 m 26 s
 * @brief 3 m 20 s
 * O(1)
 * O(1)
 * bit
 */
class Solution {
 public:
  bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
};

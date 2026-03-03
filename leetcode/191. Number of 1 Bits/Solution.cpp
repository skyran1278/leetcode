#include <cmath>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 2m 42s
 * @brief 5m 16s
 * @brief 2m 30s
 * O(k), where k is the number of 1 bits.
 * O(1)
 */
class Solution {
 public:
  int hammingWeight(int n) {
    int bitCount = 0;
    while (n) {
      n &= n - 1;
      bitCount++;
    }

    return bitCount;
  }
};

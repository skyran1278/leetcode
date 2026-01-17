#include <cmath>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 2 m 42 s
 * @brief 5 m 16 s
 * @brief 2 m 30 s
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

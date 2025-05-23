#include <cmath>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 2 m 42 s
 * O(log n)
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

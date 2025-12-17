#include <string>
#include <vector>

using namespace std;

/**
 * @brief 16 m 1 s
 * @brief 6 m 39 s
 * O(1) (bounded by 32 or 64 iterations — number of bits)
 * O(1)
 */
class Solution {
 public:
  // a = 20, b = 30
  // 10100
  // 11110
  int getSum(int a, int b) {
    while (b) {
      int carry = (a & b) << 1;  // carry = 010000
      int sum = a ^ b;           // sum   = 100010
      a = sum;                   // a     = 100010
      b = carry;                 // b     = 110010
    }

    return a;
  }
};

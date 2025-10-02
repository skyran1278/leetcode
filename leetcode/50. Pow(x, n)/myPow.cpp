/**
 * @brief 20 m 49 s
 * @brief 20 m 32 s
 * O(log n)
 * O(log n)
 */
class Solution {
 public:
  // x = 2.00000, n = 10
  // x = 2.00000, n = -2
  double myPow(double x, int n) {
    if (n == -__INT_MAX__ - 1) {
      n = -__INT_MAX__ + 1;
    }

    if (n < 0) {
      x = 1 / x;  // 1/2
      n = -n;     // 2
    }

    if (n == 0) {
      return 1;
    } else if (n % 2 == 0) {
      return myPow(x * x, n / 2);  // x = 4, n = 5; x = 256, n = 1
    } else {
      return x * myPow(x * x, n / 2);  // (x = 16, n = 2) * 4
    }
  }
};

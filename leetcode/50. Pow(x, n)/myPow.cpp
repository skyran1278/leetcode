/**
 * @brief 20m 49s
 * @brief 20m 32s
 * @brief 5m 57s
 * O(log n)
 * O(log n)
 */
class Solution {
 public:
  // x = 2.00000, n = 10
  // x = 2.00000, n = -2
  double myPow(double x, int n) {
    if (n == -__INT_MAX__ - 1) return myPow(1 / x, __INT_MAX__ - 1);
    if (n < 0) return myPow(1 / x, -n);
    if (n == 0) return 1;
    if (n % 2 == 0) return myPow(x * x, n / 2);
    return x * myPow(x * x, n / 2);
  }
};

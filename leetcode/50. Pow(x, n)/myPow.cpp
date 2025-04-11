#include <climits>

/**
 * @brief 20 m 49 s
 * O(log n)
 */
class Solution {
 public:
  double myPow(double x, int n) {
    if (n == INT_MIN) {
      x = 1 / x;
      n = INT_MAX - 1;
    }

    if (n < 0) {
      x = 1 / x;
      n = -n;
    }

    switch (n) {
      case 0:
        return 1;
      case 1:
        return x;
      default:
        if (n % 2 == 0) {
          return myPow(x * x, n / 2);
        }
        return x * myPow(x * x, n / 2);
    }
  }
};

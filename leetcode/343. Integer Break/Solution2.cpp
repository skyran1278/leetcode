#include <cmath>

using namespace std;

/**
 * @brief 3 m 5 s
 * @brief 4 m 39 s
 * O(1)
 * O(1)
 */
class Solution {
 public:
  int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;

    if (n % 3 == 0) {
      return pow(3, n / 3);
    } else if (n % 3 == 1) {
      return pow(3, n / 3 - 1) * 4;
    } else {
      return pow(3, n / 3) * 2;
    }
  }
};

int main() {
  Solution s;
  s.integerBreak(4);
}

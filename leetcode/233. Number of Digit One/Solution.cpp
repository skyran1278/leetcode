#include <cmath>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 19m 29s
 * @brief 30m 19s
 * @brief -- (editorial)
 * @brief 13m 17s (recall)
 * @brief 4m 38s (recall)
 * O(log n)
 * O(1)
 */
class Solution {
 public:
  // n = 201
  int countDigitOne(int n) {
    long count = 0;

    for (long digit = 1; digit <= n; digit *= 10) {
      long higher = n / (digit * 10);  // higher = 0;
      long current = n / digit % 10;   // current = 2;
      long lower = n % digit;          // lower = 1;

      if (current == 0) {
        count += higher * digit;  // count += 20;
      } else if (current == 1) {
        count += higher * digit + lower + 1;  // count += 21;
      } else {
        count += (higher + 1) * digit;  // count += 100;
      }
    }

    return static_cast<int>(count);
  }
};

int main() {
  Solution s;
  s.countDigitOne(12);
}

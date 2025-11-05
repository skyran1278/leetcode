#include <cmath>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 19 m 29 s
 * O(log n)
 * O(1)
 */
class Solution {
 public:
  // n = 13
  int countDigitOne(int n) {
    int count = 0;

    for (size_t i = 1; i <= n; i *= 10) {
      int high = n / (i * 10);     // 0
      int current = (n / i) % 10;  // 1
      int low = n % i;             // 3

      if (current == 0) {
        count += high * i;
      } else if (current == 1) {
        count += high * i + (low + 1);  // 4
      } else {
        count += (high + 1) * i;  // 2
      }
    }

    return count;
  }
};

int main() {
  Solution s;
  s.countDigitOne(12);
}

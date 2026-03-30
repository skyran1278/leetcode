#include <cmath>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 12m 46s
 * @brief 44m 53s
 * @brief 17m 27s
 * O(log n)
 * O(1)
 */
class Solution {
 public:
  // n = 11
  int findNthDigit(long n) {
    // 1-9     9   1
    // 10-99   90  2
    // 100-999 900 3
    long digitLength = 1;
    long digitCount = 9;
    long start = 1;

    while (n > digitLength * digitCount) {
      n -= digitLength * digitCount;
      start += digitCount;
      digitLength++;
      digitCount *= 10;
    }

    start += (n - 1) / digitLength;
    string value = to_string(start);
    return value[static_cast<size_t>((n - 1) % digitLength)] - '0';
  }
};

int main() {
  Solution s;
  s.findNthDigit(11);
}

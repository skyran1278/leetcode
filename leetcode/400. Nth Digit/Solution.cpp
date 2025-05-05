#include <cmath>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 看解答
 * O(log n)
 */
class Solution {
 public:
  int findNthDigit(int n) {
    long digitLength = 1;
    long count = 9;
    long start = 1;

    // Step 1: Find the range that contains the nth digit
    while (n > digitLength * count) {
      n -= digitLength * count;
      digitLength++;
      count *= 10;
      start *= 10;
    }

    // Step 2: Find the actual number
    start += (n - 1) / digitLength;

    // Step 3: Find the digit within that number
    string s = to_string(start);
    return s[(n - 1) % digitLength] - '0';
  }
};

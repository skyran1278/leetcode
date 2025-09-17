#include <string>

using namespace std;

/**
 * @brief 28 m 25 s
 * @brief 20 m 48 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // 42
  int myAtoi(string s) {
    size_t i = 0;

    // Whitespace: Ignore any leading whitespace (" ").
    while (i < s.length() && s[i] == ' ') {
      i++;
    }

    // Signedness: Determine the sign by checking if the next character is '-'
    // or '+', assuming positivity if neither present.
    int sign = 1;
    if (s[i] == '-') {
      sign = -1;
      i++;
    } else if (s[i] == '+') {
      sign = 1;
      i++;
    }

    // Conversion: Read the integer by skipping leading zeros until a non-digit
    // character is encountered or the end of the string is reached. If no
    // digits were read, then the result is 0.
    // Rounding: If the integer is out of the 32-bit signed integer range
    // [-2^31, 2^31 - 1], then round the integer to remain in the range.
    // Specifically, integers less than -2^31 should be rounded to -2^31, and
    // integers greater than 2^31 - 1 should be rounded to 2^31 - 1.
    long num = 0;  // use long to detect overflow
    while (i < s.length() && isdigit(s[i])) {
      num = num * 10 + (s[i] - '0');

      // 4. check overflow
      if (num * sign > __INT_MAX__) return __INT_MAX__;
      if (num * sign < -__INT_MAX__ - 1) return -__INT_MAX__ - 1;

      i++;
    }

    return (int)(sign * num);
  }
};

int main() {
  Solution s;
  s.myAtoi("-91283472332");
  s.myAtoi("42");
}

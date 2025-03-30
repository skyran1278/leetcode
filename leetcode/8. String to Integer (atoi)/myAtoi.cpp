#include <string>

using namespace std;

/**
 * @brief 28 m 25 s
 * O(1)
 */
class Solution {
 public:
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
    int result = 0;
    while (i < s.length() && isdigit(s[i])) {
      int digit = s[i] - '0';

      if (result > (INT_MAX - digit) / 10) {
        return (sign == 1) ? INT_MAX : INT_MIN;
      }

      result = result * 10 + digit;
      i++;
    }

    return sign * result;
  }
};

int main() {
  Solution s;
  s.myAtoi("-91283472332");
  s.myAtoi("42");
}

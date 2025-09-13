#include <algorithm>
#include <string>

using namespace std;

/**
 * @brief 21 m 49 s
 * @brief 14 m 0 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // num1 = "11", num2 = "123"
  string addStrings(string num1, string num2) {
    string result;

    int length1 = (int)num1.size() - 1;
    int length2 = (int)num2.size() - 1;

    int carry = 0;
    while (length1 >= 0 || length2 >= 0 || carry > 0) {
      int i1 = length1 >= 0 ? num1[(size_t)length1--] - '0' : 0;
      int i2 = length2 >= 0 ? num2[(size_t)length2--] - '0' : 0;

      int sum = carry + i1 + i2;
      carry = sum >= 10 ? 1 : 0;
      result.push_back('0' + (char)sum % 10);
    }

    reverse(result.begin(), result.end());

    return result;
  }
};

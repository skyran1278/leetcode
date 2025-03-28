#include <algorithm>
#include <string>

using namespace std;

/**
 * @brief 21 m 49 s
 * O(n)
 */
class Solution {
 public:
  string addStrings(string num1, string num2) {
    string result = "";

    int i = num1.size() - 1;
    int j = num2.size() - 1;

    int carry = 0;
    while (i >= 0 || j >= 0 || carry == 1) {
      int n1 = i >= 0 ? num1[i--] - '0' : 0;
      int n2 = j >= 0 ? num2[j--] - '0' : 0;

      int sum = carry + n1 + n2;

      carry = sum >= 10 ? 1 : 0;
      result.push_back((sum >= 10 ? sum - 10 : sum) + '0');
    }

    reverse(result.begin(), result.end());

    return result;
  }
};

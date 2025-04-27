#include <cmath>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 沒寫出來
 * O(n)
 * count how many times that bit appears
 */
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int unique = 0;
    for (size_t i = 0; i < 32; i++) {
      int sum = 0;
      for (auto&& num : nums) {
        sum += ((num >> i) & 1);
      }

      if ((sum % 3) != 0) {
        unique |= (1 << i);
      }
    }

    return unique;
  }
};

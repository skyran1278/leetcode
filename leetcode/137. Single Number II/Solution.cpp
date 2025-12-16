#include <cmath>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 7 m 49 s
 * @brief 5 m 46 s
 * O(n)
 * O(1)
 * count how many times that bit appears
 */
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int unique = 0;
    for (size_t i = 0; i < 32; i++) {
      int sum = 0;
      int mask = 1 << i;
      for (auto&& num : nums) {
        if (num & mask) sum++;
      }

      unique |= sum % 3 << i;
    }

    return unique;
  }
};

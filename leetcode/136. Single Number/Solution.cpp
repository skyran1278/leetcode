#include <string>
#include <vector>

using namespace std;

/**
 * @brief 6 m 13 s
 * @brief 2 m 0 s
 * O(n)
 * O(1)
 * use XOR feature
 */
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int uniqueValue = 0;
    for (auto&& num : nums) {
      uniqueValue ^= num;
    }
    return uniqueValue;
  }
};

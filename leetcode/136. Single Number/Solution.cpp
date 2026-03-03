#include <string>
#include <vector>

using namespace std;

/**
 * @brief 6m 13s
 * @brief 2m 0s
 * @brief 1m 24s
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

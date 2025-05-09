#include <string>
#include <vector>

using namespace std;

/**
 * @brief 6 m 13 s
 * O(n)
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

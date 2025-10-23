#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 7 m 28 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // nums = [3,2,3]
  int majorityElement(vector<int>& nums) {
    int major = 0;
    int count = 0;

    // major = 3
    // count = 1
    for (auto&& num : nums) {
      if (num == major) {
        count++;
      } else if (count-- <= 0) {
        major = num;
        count = 1;
      }
    }

    return major;
  }
};

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * O(n) with O(1) space
 */
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int major = 0;
    int count = 0;
    for (auto&& num : nums) {
      if (num == major) {
        count++;
      } else if (count-- < 0) {
        major = num;
        count = 1;
      }
    }

    return major;
  }
};

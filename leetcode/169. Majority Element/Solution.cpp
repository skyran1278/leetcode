#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 11 m 28 s
 * O(n)
 */
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> map;

    for (auto&& num : nums) {
      if (map[num]) {
        map[num] += 1;
      } else {
        map[num] = 1;
      }
    }

    int maxNum = 0;
    int maxCount = 0;
    for (auto&& [num, count] : map) {
      if (count > maxCount) {
        maxNum = num;
        maxCount = count;
      }
    }
    return maxNum;
  }
};

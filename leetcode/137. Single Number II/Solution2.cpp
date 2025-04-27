#include <cmath>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 沒寫出來
 * O(n)
 * First time you see a number → mark it in once.
 * Second time you see it → move it to twice.
 * Third time you see it → clear it from once and twice (via the & ~other part).
 */
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int once = 0;
    int twice = 0;
    for (auto&& num : nums) {
      once = (once ^ num) & ~twice;
      twice = (twice ^ num) & ~once;
    }
    return once;
  }
};

#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 24m 55s
 * @brief 20m 46s
 * @brief 38m 54s
 * @brief 50m 34s
 * @brief 23m 19s
 * @brief 42m 33s
 * O(1)
 * O(1)
 */
class Solution {
 public:
  vector<int> findClosedNumbers(int num) {
    if (num == __INT_MAX__) return {-1, -1};
    if (num == 1) return {2, -1};

    // 0110 -> 1001
    int large = num;
    for (int i{0}; i < 30; ++i) {
      bool cur = num & (1 << i);
      bool next = num & (1 << (i + 1));

      if (cur && !next) {
        large |= 1 << (i + 1);
        large &= ~(1 << i);

        int high = i - 1;
        int low = 0;
        while (high > low) {
          while (high > low && !(large & (1 << high))) high--;
          while (high > low && large & (1 << low)) low++;

          if (high > low) {
            large &= ~(1 << high);
            large |= 1 << low;
          }
        }
        break;
      }
    }

    // 1001 -> 0110
    int small = num;
    for (int i{0}; i < 30; ++i) {
      bool cur = num & (1 << i);
      bool next = num & (1 << (i + 1));

      if (!cur && next) {
        small |= 1 << i;
        small &= ~(1 << (i + 1));

        int high = i - 1;
        int low = 0;
        while (high > low) {
          while (high > low && small & (1 << high)) high--;
          while (high > low && !(small & (1 << low))) low++;

          if (high > low) {
            small |= 1 << high;
            small &= ~(1 << low);
          }
        }

        break;
      }
    }

    return {large, small};
  }
};

int main() {
  Solution s;
  s.findClosedNumbers(1024);
  s.findClosedNumbers(124);
  s.findClosedNumbers(67);
}

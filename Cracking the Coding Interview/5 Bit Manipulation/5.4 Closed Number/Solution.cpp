#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 24 m 55 s
 * @brief 20 m 46 s
 * @brief 38 m 54 s
 * @brief 50 m 34 s
 * feel hard, need more time to understand it
 * O(1)
 * O(1)
 */
class Solution {
 public:
  vector<int> findClosedNumbers(int num) {
    int big = -1;
    for (size_t i = 0; i < 31; i++) {
      bool currentIs1 = num & 1 << i;
      bool nextIs0 = !(num & 1 << i + 1);

      if (currentIs1 && nextIs0) {
        big = num;
        big &= ~(1 << i);
        big |= 1 << i + 1;

        int left = 0;
        int right = i - 1;
        while (left < right) {
          while (left < right && num & 1 << left) {
            left++;
          }
          while (left < right && !(num & 1 << right)) {
            right--;
          }

          if (left < right) {
            big |= 1 << left;
            big &= ~(1 << right);
          }

          left++;
          right--;
        }

        break;
      }
    }

    int small = -1;
    for (size_t i = 0; i < 31; i++) {
      bool currentIs0 = !(num & 1 << i);
      bool nextIs1 = num & 1 << i + 1;

      if (currentIs0 && nextIs1) {
        small = num;
        small |= 1 << i;
        small &= ~(1 << i + 1);

        int left = 0;
        int right = i - 1;
        while (left < right) {
          while (left < right && !(num & 1 << left)) {
            left++;
          }
          while (left < right && num & 1 << right) {
            right--;
          }

          if (left < right) {
            small &= ~(1 << left);
            small |= 1 << right;
          }

          left++;
          right--;
        }

        break;
      }
    }

    if (num == __INT_MAX__) {
      big = -1;
    }

    return {big, small};
  }
};

int main() {
  Solution s;
  s.findClosedNumbers(1024);
  s.findClosedNumbers(124);
  s.findClosedNumbers(67);
}

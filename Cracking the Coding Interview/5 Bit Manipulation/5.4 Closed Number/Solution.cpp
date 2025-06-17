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
 * feel hard, need more time to understand it
 */
class Solution {
 public:
  vector<int> findClosedNumbers(int num) {
    int large = num;
    for (size_t i = 0; i < 31; i++) {
      bool currentIs1 = (1 << i) & num;
      bool nextIs0 = !((1 << i + 1) & num);
      if (currentIs1 && nextIs0) {
        large &= ~(1 << i);
        large |= (1 << i + 1);

        int left = i - 1;
        int right = 0;
        while (left > right) {
          while (left > right && !((1 << left) & num)) {
            left--;
          }
          while (left > right && ((1 << right) & num)) {
            right++;
          }
          if (left > right) {
            large &= ~(1 << left);
            large |= (1 << right);
          }

          left--;
          right++;
        }

        break;
      }
    }

    int small = num;
    for (size_t i = 1; i < 32; i++) {
      bool currentIs1 = (1 << i) & num;
      bool previousIs0 = !((1 << i - 1) & num);
      if (currentIs1 && previousIs0) {
        small &= ~(1 << i);
        small |= (1 << i - 1);

        int left = i - 2;
        int right = 0;
        while (left > right) {
          while (left > right && ((1 << left) & num)) {
            left--;
          }
          while (left > right && !((1 << right) & num)) {
            right++;
          }
          if (left > right) {
            small &= ~(1 << right);
            small |= (1 << left);
          }
          left--;
          right++;
        }

        break;
      }
    }

    if (large == num || num == __INT_MAX__) {
      large = -1;
    }

    return {large, small == num ? -1 : small};
  }
};

int main() {
  Solution s;
  s.findClosedNumbers(1024);
  s.findClosedNumbers(124);
  s.findClosedNumbers(67);
}

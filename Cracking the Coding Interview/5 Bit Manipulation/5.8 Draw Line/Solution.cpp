#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 13m 18s
 * @brief 1 hrs 31m 29s
 * @brief 27m 35s
 * @brief 40m 39s
 *
 */
class Solution {
 public:
  vector<int> drawLine(int length, int w, int x1, int x2, int y) {
    vector<int> screen(length);
    int width = w / 32;
    int height = length / width;

    int start = 0;
    int end = 31;
    for (int i = y * width; i < (y + 1) * width; ++i) {
      if (x1 > end || x2 < start) {
        //    start --- end
        //   x1 --- x2
        //    start --- end
        //             x1 --- x2
        screen[i] = 0;
      } else if (x1 <= start && x2 >= end) {
        //    start --- end
        //      x1 ----- x2
        screen[i] = -1;
      } else {
        //    start --- end
        //      x1 --- x2
        //    start --- end
        //        x1 --- x2
        //    start --- end
        //        x1 - x2
        int leadingZero = max(x1 - start, 0);
        int trailingZero = max(end - x2, 0);

        int leading = static_cast<int>(~0u >> leadingZero);
        int trailing = static_cast<int>(~0u << trailingZero);

        screen[i] = leading & trailing;
      }

      start += 32;
      end += 32;
    }

    return screen;
  }
};

int main() {
  Solution s;
  s.drawLine(2, 64, 0, 52, 0);
  s.drawLine(24, 96, 2, 19, 5);
  s.drawLine(15, 96, 81, 95, 1);
  s.drawLine(1, 32, 30, 31, 0);
}

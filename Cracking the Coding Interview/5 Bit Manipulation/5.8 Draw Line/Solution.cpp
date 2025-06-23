#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 13 m 18 s
 *
 */
class Solution {
 public:
  vector<int> drawLine(int length, int w, int x1, int x2, int y) {
    vector<int> results(length);
    int intPerRow = w / 32;
    int rowStart = y * intPerRow;
    int rowEnd = rowStart + intPerRow;

    for (size_t i = rowStart; i < rowEnd; i++) {
      int begin = (i - rowStart) * 32;
      int end = begin + 31;
      if (begin > x2 || end < x1) {
        // Entire word is outside the line range
        results[i] = 0;
      } else if (begin >= x1 && end <= x2) {
        // Entire word is within the line range
        results[i] = -1;
      } else if (begin >= x1 && end > x2) {
        int zeroLength = end - x2;
        results[i] = ~((1 << zeroLength) - 1);
      } else if (begin < x1 && end <= x2) {
        int oneLength = end - x1 + 1;
        results[i] = (1 << oneLength) - 1;
      } else {
        int left = ~((1 << end - x2) - 1);
        int right = (1 << end - x1 + 1) - 1;
        results[i] = left & right;
      }
    }

    return results;
  }
};

int main() {
  Solution s;
  s.drawLine(2, 64, 0, 52, 0);
  s.drawLine(24, 96, 2, 19, 5);
  s.drawLine(15, 96, 81, 95, 1);
  s.drawLine(1, 32, 30, 31, 0);
}

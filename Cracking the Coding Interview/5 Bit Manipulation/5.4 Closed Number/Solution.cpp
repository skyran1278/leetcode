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
 * @brief 23 m 19 s
 * feel hard, need more time to understand it
 * O(1)
 * O(1)
 */
class Solution {
 public:
  vector<int> findClosedNumbers(int num) {
    // 01 -> 10
    int smallest = -1;
    for (int i = 0; i < 30; i++) {
      bool cur = num & 1 << i;
      bool next = num & 1 << i + 1;
      if (cur && !next) {
        smallest = (num & ~(1 << i)) | 1 << i + 1;
        int high = i - 1;
        int low = 0;
        while (high > low) {
          while (high > low && !(num & 1 << high)) high--;
          while (high > low && num & 1 << low) low++;
          if (high > low) {
            smallest = (smallest & ~(1 << high)) | 1 << low;
            high--;
            low++;
          }
        }
        break;
      }
    }

    // 10 -> 01
    int largest = -1;
    for (int i = 0; i < 30; i++) {
      bool cur = num & 1 << i;
      bool next = num & 1 << i + 1;
      if (!cur && next) {
        largest = (num & ~(1 << i + 1)) | 1 << i;
        int high = i - 1;
        int low = 0;
        while (high > low) {
          while (high > low && num & 1 << high) high--;
          while (high > low && !(num & 1 << low)) low++;
          if (high > low) {
            largest = (largest & ~(1 << low)) | 1 << high;
            high--;
            low++;
          }
        }
        break;
      }
    }

    return {smallest, largest};
  }
};

int main() {
  Solution s;
  s.findClosedNumbers(1024);
  s.findClosedNumbers(124);
  s.findClosedNumbers(67);
}

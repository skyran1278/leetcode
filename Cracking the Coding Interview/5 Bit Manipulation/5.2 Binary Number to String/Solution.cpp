#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 10 m 32 s
 * binary in fraction
 * O(1)
 * O(1)
 */
class Solution {
 public:
  string printBin(double num) {
    string result = "0.";
    while (num > 0 && result.size() < 32) {
      num *= 2;

      if (num >= 1) {
        num--;
        result.push_back('1');
      } else {
        result.push_back('0');
      }
    }

    return num == 0 ? result : "ERROR";
  }
};

int main() {
  Solution s;
  s.printBin(0.625);
}

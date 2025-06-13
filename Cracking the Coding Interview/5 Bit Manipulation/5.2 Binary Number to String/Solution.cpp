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
    string binaryRepresented = "0.";
    while (num > 0 && binaryRepresented.size() <= 32) {
      num *= 2;
      if (num >= 1) {
        num -= 1;
        binaryRepresented.append("1");
      } else {
        binaryRepresented.append("0");
      }
    }

    if (num > 0) {
      return "ERROR";
    }

    return binaryRepresented;
  }
};

int main() {
  Solution s;
  s.printBin(0.625);
}

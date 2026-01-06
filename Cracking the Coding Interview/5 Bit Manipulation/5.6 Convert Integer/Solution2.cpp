#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 19 m 57 s
 * O(1)
 * O(1)
 */
class Solution {
 public:
  int convertInteger(int A, int B) {
    // Brian Kernighan may Overflow when 1000... (-__INT_MAX__ - 1)
    unsigned n = static_cast<unsigned>(A ^ B);
    int count = 0;
    while (n) {
      n = n & (n - 1);
      count++;
    }

    return count;
  }
};

int main() {
  Solution s;
  s.convertInteger(29, 15);
}

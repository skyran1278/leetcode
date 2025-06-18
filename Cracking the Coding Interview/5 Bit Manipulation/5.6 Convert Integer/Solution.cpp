#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 3 m 27 s
 * O(1)
 * O(1)
 */
class Solution {
 public:
  int convertInteger(int A, int B) {
    int c = A ^ B;
    int count = 0;
    for (size_t i = 0; i < 32; i++) {
      if (c & 1 << i) {
        count++;
      }
    }
    return count;
  }
};

int main() {
  Solution s;
  s.convertInteger(29, 15);
}

#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 28m 51s
 * @brief 55m 4s
 * @brief 34m 21s
 * can skip for loop
 * O(1)
 * O(1)
 */
class Solution {
 public:
  int insertBits(int N, int M, int i, int j) {
    int mask = (j < 31 ? (~0 << (j + 1)) : 0) | ((1 << i) - 1);
    return (N & mask) | (M << i);
  }
};

int main() {
  Solution s;
  s.insertBits(2032243561, 10, 24, 29);
}

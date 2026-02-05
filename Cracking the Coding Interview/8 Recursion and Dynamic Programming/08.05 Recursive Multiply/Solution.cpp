#include <algorithm>
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
 * @brief 18 m 19 s
 * @brief 7 m 58 s
 * O(log n)
 * O(log n)
 */
class Solution {
 public:
  int multiply(int A, int B) {
    if (A < B) multiply(B, A);

    if (B == 0) return 0;
    if (B == 1) return A;
    if (B & 1) return multiply(A, B - 1) + A;

    return multiply(A + A, B >> 1);
  }
};

#include <vector>

using namespace std;

/**
 * @brief 5m 41s
 * O(logn)
 * O(1)
 */
class Solution {
 public:
  bool isUgly(int n) {
    if (n <= 0) return false;
    for (int factor : {2, 3, 5}) {
      while (n % factor == 0) n /= factor;
    }
    return n == 1;
  }
};

int main() { Solution s; }

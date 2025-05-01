#include <string>
#include <vector>

using namespace std;

/**
 * @brief 12 m 27 s
 * O(n^2)
 * DP
 */
class Solution {
 public:
  int integerBreak(int n) {
    vector<int> maxProducts(n + 1);
    maxProducts[1] = 0;
    maxProducts[2] = 1;
    for (size_t i = 3; i < n + 1; i++) {
      int maxProduct = 0;
      int left = 1;
      int right = i - 1;
      while (left <= right) {
        int maxLeft = max(maxProducts[left], left);
        int maxRight = max(maxProducts[right], right);
        if (maxLeft * maxRight > maxProduct) {
          maxProduct = maxLeft * maxRight;
        }
        left++;
        right--;
      }

      maxProducts[i] = maxProduct;
    }

    return maxProducts[n];
  }
};

int main() {
  Solution s;
  s.integerBreak(4);
}

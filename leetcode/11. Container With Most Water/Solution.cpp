#include <string>
#include <vector>

using namespace std;

/**
 * @brief 14 m 1 s
 * O(n)
 */
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxContainer = 0;

    while (left < right) {
      int h = min(height[left], height[right]);
      int container = h * (right - left);
      if (container > maxContainer) {
        maxContainer = container;
      }

      if (height[left] > height[right]) {
        right--;
      } else {
        left++;
      }
    }

    return maxContainer;
  }
};

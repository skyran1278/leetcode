#include <string>
#include <vector>

using namespace std;

/**
 * @brief 14 m 1 s
 * @brief 7 m 52 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // height = [1,8,6,2,5,4,8,3,7]
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;  // 8

    int maxContainer = 0;
    while (left < right) {
      int container = min(height[left], height[right]) * (right - left);  // 49
      if (container > maxContainer) {
        maxContainer = container;
      }

      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }

    return maxContainer;
  }
};

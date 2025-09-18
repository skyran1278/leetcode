#include <vector>

using namespace std;

/**
 * @brief 9 m 12 s
 * O(log n)
 * O(1)
 */
class Solution {
 public:
  // nums = [-1,0,3,5,9,12], target = 9
  // nums = [-1,0,3,5,9,12], target = 2
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;  // right = 5

    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] > target) {
        // right = 1
        right = mid - 1;
      } else if (nums[mid] < target) {
        // left = 1
        left = mid + 1;
      } else {
        return mid;
      }
    }

    return -1;
  }
};

int main() {
  Solution s;
  vector<int> s5 = {-1};
  s.search(s5, 2);
  vector<int> s4 = {5};
  s.search(s4, -5);
  vector<int> s3 = {-1, 0, 3, 5, 9, 12};
  s.search(s3, 9);
  vector<int> s1 = {-1, 0, 3, 5, 9, 12};
  s.search(s1, 2);
  vector<int> s2 = {2, 5};
  s.search(s2, 2);
}

#include <stack>
#include <vector>

using namespace std;

/**
 * @brief 35 m 49 s
 * @brief 13 m 2 s
 * @brief 3 m 27 s
 * @brief 4 m 52 s
 * If you face east (nums[right]), you always know whether to turn left or right
 * to reach the treasure. If you face west (nums[left]), sometimes you don’t
 * even know if the treasure is behind you.
 * O(log n)
 * O(1)
 */
class Solution {
 public:
  // nums = [2,2,2,0,1]
  // nums = [1,3,5]
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
      int pivot = (left + right) / 2;
      if (nums[pivot] < nums[right]) {
        right = pivot;
      } else if (nums[pivot] > nums[right]) {
        left = pivot + 1;
      } else {
        right -= 1;
      }
    }

    return nums[right];
  }
};

int main() {
  Solution s;
  vector<int> s5 = {2, 0, 1, 1, 1};
  s.findMin(s5);
  vector<int> s4 = {10, 1, 10, 10, 10};
  s.findMin(s4);
  vector<int> s3 = {3, 1, 3};
  s.findMin(s3);
  vector<int> s2 = {2, 2, 2, 0, 1};
  s.findMin(s2);
  vector<int> s1 = {1, 3, 5};
  s.findMin(s1);
}

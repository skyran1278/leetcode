#include <queue>
#include <vector>

using namespace std;

/**
 * @brief 7 m
 * @brief 9 m 9 s
 * O(n log k)
 * O(n)
 */
class Solution {
 public:
  // nums = [3,2,1,5,6,4], k = 2
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> heap;

    for (size_t i = 0; i < k; i++) {
      heap.push(nums[i]);
    }

    for (size_t i = k; i < nums.size(); i++) {
      if (heap.top() < nums[i]) {
        heap.pop();
        heap.push(nums[i]);
      }
    }

    return heap.top();
  }
};

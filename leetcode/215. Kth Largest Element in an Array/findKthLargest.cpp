#include <queue>
#include <vector>

using namespace std;

/**
 * @brief 7 m
 * O(nlog n)
 */
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<double, vector<double>, greater<double>> heap;

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

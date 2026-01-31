#include <deque>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 40 m 39 s
 * @brief 24 m 5 s
 * @brief 17 m 5 s
 * @brief 11 m 43 s
 * @brief 10 m 3 s
 * @brief 9 m 34 s
 * Monotonic Deque
 * O(n)
 * O(k)
 */
class Solution {
 public:
  // nums = [1,3,-1,-3,5,3,6,7], k = 3
  vector<int> maxSlidingWindow(vector<int>& nums, size_t k) {
    vector<int> results;
    deque<size_t> window;

    for (size_t i = 0; i < nums.size(); i++) {
      if (!window.empty() && window.front() + k <= i) {
        // 4. window = [2, 3]
        window.pop_front();
      }

      while (!window.empty() && nums[window.back()] <= nums[i]) {
        // 1. window = []
        // 4. window = []
        window.pop_back();
      }

      // 0. window = [0]
      // 1. window = [1]
      // 2. window = [1, 2]
      // 3. window = [1, 2, 3]
      // 4. window = [4]
      window.push_back(i);

      if (i + 1 >= k) {
        // 2. results = [3]
        // 3. results = [3, 3]
        // 4. results = [3, 3, 5]
        results.push_back(nums[window.front()]);
      }
    }

    return results;
  }
};

int main() {
  Solution s;

  vector<int> s2 = {1, 3, 1, 2, 0, 5};
  s.maxSlidingWindow(s2, 3);

  vector<int> s1 = {1, 3, -1, -3, 5, 3, 6, 7};
  s.maxSlidingWindow(s1, 3);
}

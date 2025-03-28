#include <climits>
#include <deque>
#include <set>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 40 m 39 s
 * O(n)
 */
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> window;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
      // Remove indices outside the current window
      if (!window.empty() && window.front() <= i - k) window.pop_front();

      // Remove elements smaller than the current one
      while (!window.empty() && nums[window.back()] <= nums[i])
        window.pop_back();

      window.push_back(i);

      // Add to result once window has at least k elements
      if (i >= k - 1) result.push_back(nums[window.front()]);
    }

    return result;
  }
};

int main() {
  Solution s;

  vector<int> s2 = {1, 3, 1, 2, 0, 5};
  s.maxSlidingWindow(s2, 3);

  vector<int> s1 = {1, 3, -1, -3, 5, 3, 6, 7};
  s.maxSlidingWindow(s1, 3);
}

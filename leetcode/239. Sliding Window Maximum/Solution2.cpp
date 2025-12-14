#include <array>
#include <queue>
#include <vector>

using namespace std;

/**
 * @brief 40 m 0 s
 * O(n)
 * O(k)
 */
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    struct Compare {
      bool operator()(array<int, 2> a, array<int, 2> b) { return a[1] < b[1]; };
    };
    priority_queue<array<int, 2>, vector<array<int, 2>>, Compare> heap;

    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      heap.push({i, nums[i]});
      while (heap.top()[0] <= i - k) heap.pop();

      if (i >= k - 1) result.push_back(heap.top()[1]);
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

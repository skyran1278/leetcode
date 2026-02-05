#include <algorithm>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 12 m 54 s
 * @brief 5 m 10 s
 * @brief 5 m 46 s
 * @brief 6 m 22 s
 * O(n + k)
 * O(n + k)
 * depends on whether the sorting algorithm used within each bucket is stable.
 */
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    int smallest = *min_element(nums.begin(), nums.end());
    int largest = *max_element(nums.begin(), nums.end());
    size_t bucketCount = (largest - smallest) / 10 + 1;
    vector<vector<int>> buckets(bucketCount);

    for (auto&& num : nums) {
      size_t i = (num - smallest) / 10;
      buckets[i].push_back(num);
    }

    for (auto&& bucket : buckets) {
      sort(bucket.begin(), bucket.end());
    }

    size_t i = 0;
    for (auto&& bucket : buckets) {
      for (auto&& num : bucket) {
        nums[i++] = num;
      }
    }

    return nums;
  }
};

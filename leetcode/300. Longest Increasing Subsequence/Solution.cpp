#include <vector>

using namespace std;

/**
 * @brief 1 hrs 2 m 59 s
 * O(n^2)
 */
class Solution2 {
 public:
  int lengthOfLIS(vector<int>& nums) {
    size_t n = nums.size();
    vector<int> dp(n, 1);

    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
      int num = nums[i];

      for (size_t j = i + 1; j < n; j++) {
        if (num < nums[j] && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
        }
      }
    }

    int longest = 1;
    for (size_t i = 0; i < dp.size(); i++) {
      if (dp[i] > longest) {
        longest = dp[i];
      }
    }

    return longest;
  }
};

// O(n log n)
// greedy + binary search
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    size_t n = nums.size();

    vector<int> tails = {nums[0]};
    for (size_t i = 1; i < n; i++) {
      int num = nums[i];
      if (num > tails.back()) {
        tails.push_back(num);
        continue;
      }

      int left = 0;
      int right = tails.size();
      int mid = 0;
      while (left <= right) {
        mid = (left + right) >> 1;
        if (num > tails[mid]) {
          left = ++mid;
        } else if (num < tails[mid]) {
          right = mid - 1;
        } else {
          break;
        }
      }
      tails[mid] = num;
    }

    return tails.size();
  }
};

int main() {
  Solution s;

  //   vector<int> s3 = {1, 3, 6, 7, 9, 4, 10, 5, 6};
  //   s.lengthOfLIS(s3);
  vector<int> s2 = {4, 10, 4, 3, 8, 9};
  s.lengthOfLIS(s2);
  //   vector<int> s1 = {0, 1, 0, 3, 2, 3};
  //   s.lengthOfLIS(s1);
}

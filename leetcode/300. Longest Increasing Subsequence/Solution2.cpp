#include <vector>

using namespace std;

/**
 * @brief 1 hrs 2 m 59 s
 * @brief 8 m 32 s
 * O(n^2)
 * O(n)
 */
class Solution {
 public:
  // nums = [10,9,2,5,3,7,101,18]
  int lengthOfLIS(vector<int>& nums) {
    size_t n = nums.size();
    vector<int> dp(n, 1);  // dp = [1,1,1,2,2,1,1,1]

    // [1,1,1,2,2,3,4,4]
    int longest = 1;
    for (size_t i = 1; i < n; i++) {
      for (size_t j = 0; j < i; j++) {
        if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
        }
      }

      if (dp[i] > longest) {
        longest = dp[i];
      }
    }

    return longest;
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

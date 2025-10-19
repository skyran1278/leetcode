#include <vector>

using namespace std;

/**
 * @brief 9 m 20 s
 * @brief 2 m 20 s
 * O(nlogn)
 * O(n)
 */
class Solution {
 public:
  // nums = [10,9,2,5,3,7,101,18]
  int lengthOfLIS(vector<int>& nums) {
    vector<int> subsequence;

    for (auto&& num : nums) {
      auto it = lower_bound(subsequence.begin(), subsequence.end(), num);
      if (it == subsequence.end()) {
        subsequence.push_back(num);
      } else {
        *it = num;
      }
    }

    return subsequence.size();
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

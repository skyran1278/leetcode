#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 0 m 48 s
 * @brief 4 m 10 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // numbers = [2,7,11,15], target = 9
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    // left = 0, right = 3
    int sum = __INT_MAX__;
    while (sum != target) {
      sum = numbers[left] + numbers[right];
      if (sum > target) {
        // right = 2
        // right = 1
        right--;
      } else if (sum < target) {
        left++;
      }
    }

    return {left + 1, right + 1};
  }
};

int main() {
  Solution s;

  vector<int> v = {-10, -8, -2, 1, 2, 5, 6};
  int target = 0;
  vector<int> s1 = s.twoSum(v, target);

  for (int value : s1) {
    std::cout << value << " ";
  }
}

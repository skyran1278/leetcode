#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 0 m 48 s
 * O(n)
 */
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;

    while (numbers[i] + numbers[j] != target) {
      if (numbers[i] + numbers[j] > target) {
        j--;
      } else if (numbers[i] + numbers[j] < target) {
        i++;
      }
    }

    vector<int> index = {i + 1, j + 1};
    return index;
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

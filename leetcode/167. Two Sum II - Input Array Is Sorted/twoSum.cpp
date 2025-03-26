#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size(); i++) {
      int x1 = numbers[i];
      int x2 = target - x1;

      for (int j = i + 1; j < numbers.size(); j++) {
        if (numbers[j] == x2) {
          vector<int> index = {i + 1, j + 1};
          return index;
        }
      }
    }

    vector<int> index;
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

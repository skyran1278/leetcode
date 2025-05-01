#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> grayCode(int n) {
    int count = pow(2, n);
    vector<int> result(count);
    result[0] = 0;

    int i = 1;
    while (i < count) {
      int j = 0;
      while (j < n) {
        result[i] = result[i - 1] + pow(2, j);
      }
    }
  }
};

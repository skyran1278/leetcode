#include <string>
#include <vector>

using namespace std;

/**
 * @brief reading ans
 * O(n)
 */
class Solution {
 public:
  vector<int> grayCode(int n) {
    int count = 1 << n;
    vector<int> result(count);
    result[0] = 0;

    for (size_t i = 0; i < count; i++) {
      result[i] = i ^ (i >> 1);
    }

    return result;
  }
};

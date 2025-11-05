#include <string>
#include <vector>

using namespace std;

/**
 * @brief 4 m 19 s
 * @brief 4 m 20 s
 * O(2ⁿ)
 * O(2ⁿ)
 */
class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> result = {0};

    for (size_t i = 0; i < n; i++) {
      int add = 1 << i;
      for (int j = result.size() - 1; j >= 0; j--) {
        result.push_back(result[j] | add);
      }
    }

    return result;
  }
};

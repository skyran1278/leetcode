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
 * @brief 30s
 * @brief 4m 9s
 * @brief 2m 21s
 * O(n²)
 * O(1)
 * unstable sort
 */
class Solution {
 public:
  void selectionSort(vector<int>& arr) {
    for (size_t i = 0; i + 1 < arr.size(); i++) {
      int select = i;
      for (size_t j = i + 1; j < arr.size(); j++) {
        if (arr[j] < arr[select]) {
          select = j;
        }
      }
      swap(arr[i], arr[select]);
    }
  }
};

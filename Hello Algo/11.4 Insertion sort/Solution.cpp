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
 * @brief 13 m 44 s
 * O(n^2)
 * O(1)
 * stable
 */
class Solution {
 public:
  // 9 7 3 7 8
  void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
      int base = arr[i];

      int j = i - 1;
      while (j >= 0 && arr[j] > base) {
        arr[j + 1] = arr[j];  // Move arr[j] to the right by one position
        j--;
      }

      arr[j + 1] = base;
    }
  }
};

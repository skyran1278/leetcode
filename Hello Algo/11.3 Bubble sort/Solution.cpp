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
 * @brief 1 m 44 s
 * @brief 5 m 51 s
 * repeatedly swaps adjacent elements
 * O(n²)
 * O(1)
 * stable sort
 */
class Solution {
 public:
  void bubbleSort(vector<int>& arr) {
    for (size_t i = 0; i + 1 < arr.size(); i++) {
      bool swapped = false;

      for (int j = arr.size() - 1; j > i; j--) {
        if (arr[j - 1] > arr[j]) {
          swap(arr[j - 1], arr[j]);
          swapped = true;
        }
      }

      if (!swapped) return;
    }
  }
};

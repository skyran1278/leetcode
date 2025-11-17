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

      for (size_t j = 0; j + i + 1 < arr.size(); j++) {
        if (arr[j + 1] < arr[j]) {
          swap(arr[j], arr[j + 1]);
          swapped = true;
        }
      }

      if (!swapped) break;
    }
  }
};

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
 * @brief 1m 44s
 * @brief 5m 51s
 * @brief 5m 40s
 * repeatedly swaps adjacent elements
 * O(n²)
 * O(1)
 * stable sort
 */
class Solution {
 public:
  void bubbleSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());

    for (int i = 0; i < n; ++i) {
      bool swapped = false;
      for (int j = n - 1; j > i; --j) {
        if (arr[j] < arr[j - 1]) {
          swap(arr[j], arr[j - 1]);
          swapped = true;
        }
      }
      if (!swapped) return;
    }
  }
};

int main() {
  Solution sol;
  vector<int> arr{5, 1, 4, 2, 8};
  sol.bubbleSort(arr);
  for (int num : arr) {
    printf("%d ", num);
  }
  printf("\n");
  return 0;
}

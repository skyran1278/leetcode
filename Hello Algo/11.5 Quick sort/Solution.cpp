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
 * @brief 13m 21s
 * @brief 39m 42s
 * @brief 7m 9s
 * @brief 24m 58s
 * @brief 6m 29s
 * @brief 13m 59s
 * O(nlogn)
 * O(n)
 * unstable
 */
class Solution {
 public:
  void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int pivot = partition(arr, low, high);

    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }

 public:
  int partition(vector<int>& arr, int low, int high) {
    int pivot = low;
    while (low < high) {
      while (low < high && arr[high] >= arr[pivot]) high--;
      while (low < high && arr[low] <= arr[pivot]) low++;
      swap(arr[low], arr[high]);
    }

    swap(arr[pivot], arr[low]);

    return low;
  }
};

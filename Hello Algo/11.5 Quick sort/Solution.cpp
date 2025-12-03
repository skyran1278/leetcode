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
 * @brief 13 m 21 s
 * O(nlogn)
 * O(n)
 * unstable
 */
class Solution {
 public:
  void quickSort(vector<int>& arr, int low, int high) {
    if (low > high) return;

    int pivot = partition(arr, low, high);

    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }

  int partition(vector<int>& arr, int low, int high) {
    int i = low;
    int j = high;

    while (i < j) {
      while (i < j && arr[j] >= arr[low]) j--;
      while (i < j && arr[i] <= arr[low]) i++;
      swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[low]);

    return i;
  }
};

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
 * @brief
 * O(nlogn)
 * O(n)
 * stable
 */
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }

  void mergeSort(vector<int>& arr, int l, int r) {
    if (l == r) return;

    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, mid, r);
  }

  void merge(vector<int>& arr, int l, int m, int r) {
    size_t n = r - l + 1;
    vector<int> sorted(n);

    int left = l;
    int right = m + 1;
    int i = 0;
    while (left <= m && right <= r) {
      if (arr[left] <= arr[right]) {
        sorted[i++] = arr[left++];
      } else {
        sorted[i++] = arr[right++];
      }
    }

    while (left <= m) {
      sorted[i++] = arr[left++];
    }

    while (right <= r) {
      sorted[i++] = arr[right++];
    }

    for (size_t i = 0; i < n; i++) {
      arr[l + i] = sorted[i];
    }
  }
};

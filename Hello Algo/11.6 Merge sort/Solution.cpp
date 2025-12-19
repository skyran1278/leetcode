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
 * @brief 10 m 15 s
 * O(nlogn)
 * O(n)
 * stable
 */
class Solution {
 public:
  void mergeSort(vector<int>& arr, int l, int r) {
    if (l == r) return;

    int pivot = l + (r - l) / 2;
    mergeSort(arr, l, pivot);
    mergeSort(arr, pivot + 1, r);

    merge(arr, l, pivot, r);
  }

  void merge(vector<int>& arr, int l, int m, int r) {
    size_t n1 = m - l + 1;
    size_t n2 = r - m;
    vector<int> left(n1);
    vector<int> right(n2);

    for (size_t i = 0; i < n1; i++) {
      left[i] = arr[l + i];
    }
    for (size_t i = 0; i < n2; i++) {
      right[i] = arr[m + i + 1];
    }

    size_t i = 0;
    size_t j = 0;
    size_t k = l;
    while (i < n1 && j < n2)
      arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
  }
};

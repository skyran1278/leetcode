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
// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

/**
 * @brief 14 m 15 s
 * @brief 3 m 50 s
 * @brief 26 m 37 s
 * @brief 7 m 44 s
 * O(nlogn)
 * O(1)
 * unstable
 */
class Solution {
 public:
  // Function to sort an array using Heap Sort.
  void heapSort(vector<int>& arr) {
    size_t n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
      heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
    }
  }

  void heapify(vector<int>& arr, size_t n, size_t i) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left]) largest = left;
    if (right < n && arr[largest] < arr[right]) largest = right;
    if (largest != i) {
      swap(arr[largest], arr[i]);
      heapify(arr, n, largest);
    }
  }
};

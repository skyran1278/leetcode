#include <algorithm>
#include <array>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void countingSort(int arr[], int n, int digit) {
  constexpr int countsSize = 10;
  array<int, countsSize> counts{};

  for (int i = 0; i < n; ++i) {
    ++counts[arr[i] / digit % countsSize];
  }

  for (int i = 1; i < countsSize; ++i) {
    counts[i] += counts[i - 1];
  }

  // arr = 1 9 345 2
  // counts = 0 0 1 2 2 2 0 0 0 3
  // result = 1 2 345 9
  vector<int> result(n);
  for (int i = n - 1; i >= 0; --i) {
    result[--counts[arr[i] / digit % countsSize]] = arr[i];
  }

  for (int i = 0; i < n; ++i) {
    arr[i] = result[i];
  }
}

/**
 * @brief 19m 15s
 * @brief 13m 43s
 * @brief 22m 29s
 * O(nk)
 * O(n + d)
 * stable
 */
void radixSort(int arr[], int n) {
  int largest = INT_MIN;

  for (int i = 0; i < n; ++i) {
    if (arr[i] > largest) largest = arr[i];
  }

  for (int digit = 1; digit <= largest; digit *= 10) {
    countingSort(arr, n, digit);
  }
}

int main() {
  int arr[] = {1, 9, 345, 2};
  int n = sizeof(arr) / sizeof(arr[0]);

  radixSort(arr, n);

  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }

  return 0;
}

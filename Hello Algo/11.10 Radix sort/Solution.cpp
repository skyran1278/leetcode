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

void countingSort(int arr[], int n, int digit) {
  vector<int> count(10, 0);

  for (size_t i = 0; i < n; i++) {
    count[arr[i] / digit % 10]++;
  }

  for (size_t i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  vector<int> result(n);
  for (int i = n - 1; i >= 0; i--) {
    result[--count[arr[i] / digit % 10]] = arr[i];
  }

  for (size_t i = 0; i < n; i++) {
    arr[i] = result[i];
  }
}

/**
 * @brief 19 m 15 s
 * @brief 13 m 43 s
 * O(nk)
 * O(n + d)
 * stable
 */
void radixSort(int arr[], int n) {
  int largest = -__INT_MAX__ - 1;
  for (size_t i = 0; i < n; i++) {
    if (arr[i] > largest) largest = arr[i];
  }

  for (int digit = 1; digit <= largest; digit *= 10) {
    countingSort(arr, n, digit);
  }
}

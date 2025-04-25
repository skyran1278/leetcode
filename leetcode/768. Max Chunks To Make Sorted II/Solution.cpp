#include <climits>
#include <queue>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 寫不出來
 * O(n)
 * maximum value on the left is ≤ the minimum value on the right
 */
class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();

    vector<int> minRights(n + 1, INT_MAX);
    for (int i = n - 1; i >= 0; i--) {
      minRights[i] = min(arr[i], minRights[i + 1]);
    }

    int chunkCount = 0;
    int maxLeft = 0;
    for (size_t i = 0; i < n; i++) {
      if (arr[i] > maxLeft) {
        maxLeft = arr[i];
      }

      if (maxLeft <= minRights[i + 1]) {
        chunkCount++;
      }
    }

    return chunkCount;
  }
};

int main() {
  Solution s;

  vector<int> s1 = {2, 1, 3, 4, 4};
  s.maxChunksToSorted(s1);
}

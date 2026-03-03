// The API isBadVersion is defined for you.
bool isBadVersion(int version);

/**
 * @brief 1m 18s
 * @brief 9m 22s
 * @brief 2m 52s
 * O(log n)
 * O(1)
 */
class Solution {
 public:
  // n = 5, bad = 4
  // n = 3, bad = 2
  int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (right > left) {
      int pivot = left + (right - left) / 2;

      if (isBadVersion(pivot)) {
        right = pivot;
      } else {
        left = pivot + 1;
      }
    }

    return right;
  }
};

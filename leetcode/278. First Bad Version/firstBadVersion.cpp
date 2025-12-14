// The API isBadVersion is defined for you.
bool isBadVersion(int version);

/**
 * @brief 1 m 18 s
 * @brief 9 m 22 s
 * @brief 2 m 52 s
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

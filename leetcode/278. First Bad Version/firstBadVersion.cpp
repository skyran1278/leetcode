// The API isBadVersion is defined for you.
bool isBadVersion(int version);

/**
 * @brief 1 m 18 s
 * O(log n)
 */
class Solution {
 public:
  int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (left < right) {
      int i = left + (right - left) / 2;

      if (isBadVersion(i)) {
        right = i;
      } else {
        left = i + 1;
      }
    }

    // 此时有 left == right，区间缩为一个点，即为答案
    return left;
  }
};

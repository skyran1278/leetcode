#include <queue>
#include <vector>

using namespace std;

/**
 * @brief
 * O(n)
 */
class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    int left = 0;
    int right = nums_.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (num < nums_[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    if (left - 1 < 0) {
      nums_.insert(nums_.begin(), num);
    } else {
      nums_.insert(nums_.begin() + left, num);
    }
  }

  double findMedian() {
    int length = nums_.size();

    if (length % 2 == 0) {
      int left = length / 2 - 1;
      int right = length / 2;
      return (nums_[left] + nums_[right]) / 2.0;
    }

    return nums_[length / 2];
  }

 private:
  vector<int> nums_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 *
 *
 */

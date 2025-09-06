#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief
 * If 99% of all integer numbers from the stream are in the range [0, 100], how
 * would you optimize your solution?
 */
class MedianFinder {
 public:
  MedianFinder() : countList_(101, 0), totalCount_(0) {}

  void addNum(int num) {
    totalCount_++;
    if (num < 0) {
      negativeOutliers_.push_back(num);
      sort(negativeOutliers_.begin(), negativeOutliers_.end());
    } else if (num > 100) {
      positiveOutliers_.push_back(num);
      sort(positiveOutliers_.begin(), positiveOutliers_.end());
    } else {
      countList_[num]++;
    }
  }

  double findMedian() {
    if (totalCount_ % 2 == 1) {
      return findKthElement(totalCount_ / 2 + 1);
    }

    int leftValue = findKthElement(totalCount_ / 2);
    int rightValue = findKthElement(totalCount_ / 2 + 1);
    return (leftValue + rightValue) / 2.0;
  }

 private:
  vector<int> countList_;
  vector<int> negativeOutliers_;
  vector<int> positiveOutliers_;
  int totalCount_;

  int findKthElement(int k) {
    int current = 0;
    if (k <= negativeOutliers_.size()) {
      return negativeOutliers_[k - 1];
    }
    current += negativeOutliers_.size();

    for (size_t i = 0; i < 101; i++) {
      if (current + countList_[i] >= k) {
        return i;
      }
      current += countList_[i];
    }

    return positiveOutliers_[k - current - 1];
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

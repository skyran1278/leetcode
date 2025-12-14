#include <queue>

using namespace std;

/**
 * @brief 23 m 32 s
 * @brief 9 m 43 s
 * addNum: O(logn)
 * findMedian: O(1)
 */
class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    leftHeap_.push(num);

    rightHeap_.push(leftHeap_.top());
    leftHeap_.pop();

    if (leftHeap_.size() < rightHeap_.size()) {
      leftHeap_.push(rightHeap_.top());
      rightHeap_.pop();
    }
  }

  double findMedian() {
    if (leftHeap_.size() > rightHeap_.size()) {
      return leftHeap_.top();
    }

    return (leftHeap_.top() + rightHeap_.top()) / 2.0;
  }

 private:
  priority_queue<int, vector<int>, less<int>> leftHeap_;
  priority_queue<int, vector<int>, greater<int>> rightHeap_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

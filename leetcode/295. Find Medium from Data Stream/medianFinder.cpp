#include <climits>
#include <queue>

using namespace std;

/**
 * @brief 23 m 32 s
 * addNum: O(logn)
 * findMedian: O(1)
 */
class MedianFinder {
 private:
  // Initialize a min heap
  priority_queue<double, vector<double>, greater<double>> minHeap;
  // Initialize a max heap
  priority_queue<double, vector<double>, less<double>> maxHeap;

  double medium = LONG_MAX;

 public:
  MedianFinder() {
    minHeap.push(LONG_MAX);
    maxHeap.push(LONG_MIN);
  }

  void addNum(int num) {
    if (medium == LONG_MAX) {
      double large = minHeap.top();
      double small = maxHeap.top();

      if (num > large) {
        medium = large;
        minHeap.pop();
        minHeap.push(num);
      } else if (num < small) {
        medium = small;
        maxHeap.pop();
        maxHeap.push(num);
      } else {
        medium = num;
      }
    } else {
      if (num > medium) {
        minHeap.push(num);
        maxHeap.push(medium);
      } else {
        maxHeap.push(num);
        minHeap.push(medium);
      }
      medium = LONG_MAX;
    }
  }

  double findMedian() {
    if (medium != LONG_MAX) {
      return medium;
    }

    return (maxHeap.top() + minHeap.top()) / 2;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 14m 40s
 * @brief 18m 33s
 * @brief 5m 30s
 * @brief 11m 52s
 *
 */
class SortedStack {
 public:
  SortedStack() {}

  void push(int val) {
    while (!sortedStack_.empty() && val > sortedStack_.top()) {
      auxiliaryStack_.push(sortedStack_.top());
      sortedStack_.pop();
    }
    sortedStack_.push(val);
    while (!auxiliaryStack_.empty()) {
      sortedStack_.push(auxiliaryStack_.top());
      auxiliaryStack_.pop();
    }
  }

  void pop() {
    if (!isEmpty()) sortedStack_.pop();
  }

  int peek() {
    if (isEmpty()) return -1;
    return sortedStack_.top();
  }

  bool isEmpty() { return sortedStack_.empty(); }

  stack<int> sortedStack_;
  stack<int> auxiliaryStack_;
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */

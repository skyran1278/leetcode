#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 14 m 40 s
 *
 */
class SortedStack {
 public:
  SortedStack() {}

  void push(int val) {
    while (!sortedStack.empty() && sortedStack.top() < val) {
      int value = sortedStack.top();
      sortedStack.pop();

      stack2_.push(value);
    }

    sortedStack.push(val);

    while (!stack2_.empty()) {
      int value = stack2_.top();
      stack2_.pop();

      sortedStack.push(value);
    }
  }

  void pop() {
    if (isEmpty()) {
      return;
    }

    sortedStack.pop();
  }

  int peek() {
    if (isEmpty()) {
      return -1;
    }
    return sortedStack.top();
  }

  bool isEmpty() { return sortedStack.empty(); }

 private:
  stack<int> sortedStack;
  stack<int> stack2_;
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */

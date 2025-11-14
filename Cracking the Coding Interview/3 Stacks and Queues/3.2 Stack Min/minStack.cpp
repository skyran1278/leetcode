#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 3 m 32 s
 * @brief 4 m 47 s
 * O(1)
 */
class MinStack {
 public:
  MinStack() {}

  void push(int val) {
    if (minStack_.empty() || val <= minStack_.top()) {
      minStack_.push(val);
    }

    stack_.push(val);
  }

  void pop() {
    int stackTop = top();
    int minTop = minStack_.top();

    if (stackTop == minTop) {
      minStack_.pop();
    }

    stack_.pop();
  }

  int top() { return stack_.top(); }

  int getMin() { return minStack_.top(); }

 private:
  stack<int> stack_;
  stack<int> minStack_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

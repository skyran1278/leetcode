#include <stack>

using namespace std;

/**
 * @brief 18 m 57 s
 * @brief 8 m 54 s
 * @brief 3 m 56 s
 * O(1)
 */
class MinStack {
 public:
  MinStack() { minStack_.push(__INT_MAX__); }

  void push(int val) {
    if (val <= minStack_.top()) {
      minStack_.push(val);
    }
    normalStack_.push(val);
  }

  void pop() {
    if (normalStack_.top() == minStack_.top()) {
      minStack_.pop();
    }
    normalStack_.pop();
  }

  int top() { return normalStack_.top(); }

  int getMin() { return minStack_.top(); }

 private:
  stack<int> normalStack_;
  stack<int> minStack_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 *
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 *
 * normalStack_ = []
 * minStack_ = [__INT_MAX__]
 *
 * normalStack_ = [-2]
 * minStack_ = [-2, __INT_MAX__]
 *
 * normalStack_ = [0, -2]
 * minStack_ = [-2, __INT_MAX__]
 *
 * normalStack_ = [-3, 0, -2]
 * minStack_ = [-3, -2, __INT_MAX__]
 *
 * normalStack_ = [0, -2]
 * minStack_ = [-2, __INT_MAX__]
 */

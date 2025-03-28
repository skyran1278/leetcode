#include <stack>

/**
 * @brief 18 m 57 s
 * O(1)
 */
class MinStack {
 public:
  std::stack<int> intStack;
  std::stack<int> minStack;

  MinStack() { minStack.push(INT_MAX); }

  void push(int val) {
    if (val <= minStack.top()) {
      minStack.push(val);
    }
    intStack.push(val);
  }

  void pop() {
    if (intStack.top() == minStack.top()) {
      minStack.pop();
    }
    intStack.pop();
  }

  int top() { return intStack.top(); }

  int getMin() { return minStack.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

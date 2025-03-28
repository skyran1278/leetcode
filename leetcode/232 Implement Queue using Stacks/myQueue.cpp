#include <stack>

/**
 * @brief 14 m 28 s
 * push: O(n), other: O(1)
 */
class MyQueue {
 public:
  std::stack<int> stack1;
  std::stack<int> stack2;

  MyQueue() {}

  void push(int x) {
    while (!stack2.empty()) {
      stack1.push(stack2.top());
      stack2.pop();
    }

    stack2.push(x);

    while (!stack1.empty()) {
      stack2.push(stack1.top());
      stack1.pop();
    }
  }

  int pop() {
    int x = stack2.top();
    stack2.pop();
    return x;
  }

  int peek() { return stack2.top(); }

  bool empty() { return stack2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

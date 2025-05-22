#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 6 m 45 s
 *
 */
class MyQueue {
 public:
  MyQueue() {}

  void push(int x) {
    while (!stack2_.empty()) {
      int value = stack2_.top();
      stack2_.pop();
      stack1_.push(value);
    }
    stack1_.push(x);

    while (!stack1_.empty()) {
      int value = stack1_.top();
      stack1_.pop();
      stack2_.push(value);
    }
  }

  int pop() {
    int value = stack2_.top();
    stack2_.pop();
    return value;
  }

  int peek() { return stack2_.top(); }

  bool empty() { return stack2_.empty(); }

 private:
  stack<int> stack1_;
  stack<int> stack2_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

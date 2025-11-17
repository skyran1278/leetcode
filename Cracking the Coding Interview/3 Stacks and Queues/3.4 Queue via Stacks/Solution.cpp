#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 6 m 45 s
 * @brief 10 m 41 s
 *
 */
class MyQueue {
 public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { primaryStack_.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int value = peek();
    auxiliaryStack_.pop();
    return value;
  }

  /** Get the front element. */
  int peek() {
    if (auxiliaryStack_.empty()) {
      while (!primaryStack_.empty()) {
        auxiliaryStack_.push(primaryStack_.top());
        primaryStack_.pop();
      }
    }

    return auxiliaryStack_.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return primaryStack_.empty() && auxiliaryStack_.empty(); }

 private:
  stack<int> primaryStack_;
  stack<int> auxiliaryStack_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

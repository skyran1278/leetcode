#include <stack>

using namespace std;

/**
 * @brief 14 m 28 s
 * @brief 13 m 54 s
 * push: O(1), other: O(mostly 1, rarely n)
 */
class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { inputStack_.push(x); }

  int pop() {
    moveInputToOutput();

    int first = outputStack_.top();
    outputStack_.pop();
    return first;
  }

  int peek() {
    moveInputToOutput();

    return outputStack_.top();
  }

  bool empty() { return inputStack_.empty() && outputStack_.empty(); }

  void moveInputToOutput() {
    if (outputStack_.empty()) {
      while (!inputStack_.empty()) {
        int last = inputStack_.top();
        inputStack_.pop();
        outputStack_.push(last);
      }
    }
  }

 private:
  stack<int> inputStack_;
  stack<int> outputStack_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 *
 * Input
 * ["MyQueue", "push", "push", "peek", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * Output
 * [null, null, null, 1, 1, false]
 *
 * stack1_ = []
 * stack2_ = []
 *
 * stack1_ = [1]
 * stack2_ = []
 *
 * stack1_ = [1, 2]
 * stack2_ = []
 *
 * stack1_ = []
 * stack2_ = [2, 1]
 *
 * stack1_ = []
 * stack2_ = [2]
 */

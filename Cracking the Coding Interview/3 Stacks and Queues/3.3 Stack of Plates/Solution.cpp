#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 20 m 24 s
 * @brief 27 m 7 s
 * @brief 16 m 14 s
 *
 */
class StackOfPlates {
 public:
  StackOfPlates(int cap) : cap_(cap) {}

  void push(int val) {
    if (cap_ == 0) {
      return;
    }

    if (stacks_.empty() || stacks_.back().size() == cap_) {
      stacks_.push_back({});
    }

    stacks_.back().push(val);
  }

  int pop() { return popAt(stacks_.size() - 1); }

  int popAt(int index) {
    if (index >= stacks_.size()) {
      return -1;
    }

    stack<int>& specificStack = stacks_[index];

    int value = specificStack.top();
    specificStack.pop();

    if (specificStack.empty()) {
      stacks_.erase(stacks_.begin() + index);
    }

    return value;
  }

 private:
  vector<stack<int>> stacks_;
  int cap_;
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */

int main() {
  StackOfPlates* obj = new StackOfPlates(1);
  obj->push(1);
  obj->push(2);
  obj->popAt(1);
  obj->pop();
  obj->pop();
}

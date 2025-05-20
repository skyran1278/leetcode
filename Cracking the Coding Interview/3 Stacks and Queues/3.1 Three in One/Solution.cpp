#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>
class ThreeInOneStack {
 public:
  explicit ThreeInOneStack(int perStack = 10)
      : capacity(perStack), data(perStack * 3), tops{-1, -1, -1} {}

  void pop(int stackNum) {
    if (!empty(stackNum)) {
      tops[stackNum]--;
    }
  }

  void push(int stackNum, const T& item) {
    ensureCapacity(stackNum);
    tops[stackNum]++;
    data[absoluteIndex(stackNum)] = item;
  }

  T peek(int stackNum) const {
    if (empty(stackNum)) throw std::runtime_error("Stack is empty");
    return data[absoluteIndex(stackNum)];
  }

  bool empty(int stackNum) const { return tops[stackNum] == -1; }

 private:
  int capacity;    // per-stack capacity
  vector<T> data;  // unified storage
  int tops[3];     // top index for each stack

  int absoluteIndex(int stackNum) const {
    return stackNum * capacity + tops[stackNum];
  }

  void ensureCapacity(int stackNum) {
    if (tops[stackNum] + 1 >= capacity) {
      int oldCapacity = capacity;
      capacity *= 2;
      vector<T> newData(capacity * 3);

      // copy all three stacks to newData
      for (int s = 0; s < 3; ++s) {
        for (int i = 0; i <= tops[s]; ++i) {
          newData[s * capacity + i] = data[s * oldCapacity + i];
        }
      }

      data = std::move(newData);
    }
  }
};

int main() {
  ThreeInOneStack<int> s(3);  // capacity = 3 per stack (total 9 slots)

  std::cout << "### Pushing Phase\n";
  for (int i = 0; i < 8; ++i) {  // push 8 items onto stack-0
    s.push(0, i);
    std::cout << "stack 0 push " << i << "   peek -> " << s.peek(0) << '\n';
  }

  for (int i = 100; i < 106; ++i) {  // push 6 items onto stack-1
    s.push(1, i);
    std::cout << "stack 1 push " << i << "   peek -> " << s.peek(1) << '\n';
  }

  for (int i = 200; i < 204; ++i) {  // push 4 items onto stack-2
    s.push(2, i);
    std::cout << "stack 2 push " << i << "   peek -> " << s.peek(2) << '\n';
  }

  std::cout << "\n### Popping Phase\n";
  while (!s.empty(0)) {
    std::cout << "stack 0 pop -> " << s.peek(0) << '\n';
    s.pop(0);
  }
  while (!s.empty(1)) {
    std::cout << "stack 1 pop -> " << s.peek(1) << '\n';
    s.pop(1);
  }
  while (!s.empty(2)) {
    std::cout << "stack 2 pop -> " << s.peek(2) << '\n';
    s.pop(2);
  }

  std::cout << "\n### Empty Check\n";
  for (int k = 0; k < 3; ++k)
    std::cout << "stack " << k << " empty? " << std::boolalpha << s.empty(k)
              << '\n';

  return 0;
}

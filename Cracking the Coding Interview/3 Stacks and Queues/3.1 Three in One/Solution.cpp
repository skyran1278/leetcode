#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>
class ThreeInOneStack {
 public:
  void pop(int stackNum) {
    if (stacks[stackNum] > arr.size() / 3 * stackNum) {
      stacks[stackNum]--;
    }
  }

  void push(int stackNum, T item) {
    if (stacks[stackNum] >= arr.size() / 3 * stackNum) {
      /* code */
    }
  }

  T peek(int stackNum) { return stacks[stackNum]; }

  boolean isEmpty(int stackNum) {
    return stacks[stackNum] == arr.size() / 3 * stackNum;
  }

 private:
  int stacks[3] = {};

  vector<T> arr;
};

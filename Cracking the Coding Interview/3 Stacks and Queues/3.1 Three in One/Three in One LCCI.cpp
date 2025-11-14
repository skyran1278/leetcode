#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 20 m 35 s
 * @brief 24 m 44 s
 *
 * Simulate
 */
class TripleInOne {
 public:
  TripleInOne(int stackSize) : _data(stackSize * 3), _stackSize(stackSize) {}

  void push(int stackNum, int value) {
    if (_tops[stackNum] + 1 < _stackSize) {
      _data[index(stackNum, ++_tops[stackNum])] = value;
    }
  }

  int pop(int stackNum) {
    if (isEmpty(stackNum)) {
      return -1;
    }

    return _data[index(stackNum, _tops[stackNum]--)];
  }

  int peek(int stackNum) {
    if (isEmpty(stackNum)) {
      return -1;
    }

    return _data[index(stackNum, _tops[stackNum])];
  }

  bool isEmpty(int stackNum) { return _tops[stackNum] == -1; }

 private:
  int _tops[3] = {-1, -1, -1};
  vector<int> _data;
  int _stackSize;

  int index(int stackNum, int offset) const {
    return stackNum * _stackSize + offset;
  }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */

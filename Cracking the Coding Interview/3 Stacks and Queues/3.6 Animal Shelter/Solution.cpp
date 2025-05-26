#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 16 m 9 s
 *
 */
class AnimalShelf {
 public:
  AnimalShelf() {}

  void enqueue(vector<int> animal) { list_.push_back(animal); }

  vector<int> dequeueAny() {
    if (list_.empty()) {
      return {-1, -1};
    }

    vector<int> value = list_.front();
    list_.pop_front();

    return value;
  }

  vector<int> dequeueDog() {
    list<vector<int>> tmpList;

    while (!list_.empty() && list_.front()[1] == 0) {
      tmpList.push_back(list_.front());
      list_.pop_front();
    }

    if (list_.empty()) {
      list_.splice(list_.begin(), tmpList);
      return {-1, -1};
    }

    vector<int> value = list_.front();
    list_.pop_front();

    list_.splice(list_.begin(), tmpList);

    return value;
  }

  vector<int> dequeueCat() {
    list<vector<int>> tmpList;

    while (!list_.empty() && list_.front()[1] == 1) {
      tmpList.push_back(list_.front());
      list_.pop_front();
    }

    if (list_.empty()) {
      list_.splice(list_.begin(), tmpList);
      return {-1, -1};
    }

    vector<int> value = list_.front();
    list_.pop_front();

    list_.splice(list_.begin(), tmpList);

    return value;
  }

 private:
  list<vector<int>> list_;
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */

int main() {
  AnimalShelf s;
  s.enqueue({0, 0});
  s.enqueue({1, 0});
  s.dequeueCat();
  s.dequeueDog();
  s.dequeueAny();
}

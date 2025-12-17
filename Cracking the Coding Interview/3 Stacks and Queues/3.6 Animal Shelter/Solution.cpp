#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 16 m 9 s
 * @brief 30 m 55 s
 *
 */
class AnimalShelf {
 public:
  AnimalShelf() {}

  void enqueue(vector<int> animal) {
    if (animal[1] == 0) {
      catQueue_.push(animal);
    } else if (animal[1] == 1) {
      dogQueue_.push(animal);
    }
  }

  vector<int> dequeueAny() {
    if (dogQueue_.empty()) return dequeueCat();
    if (catQueue_.empty()) return dequeueDog();

    vector<int>& cat = catQueue_.front();
    vector<int>& dog = dogQueue_.front();
    if (cat[0] < dog[0]) {
      return dequeueCat();
    } else {
      return dequeueDog();
    }
  }

  vector<int> dequeueDog() {
    if (dogQueue_.empty()) return {-1, -1};
    vector<int> dog = dogQueue_.front();
    dogQueue_.pop();
    return dog;
  }

  vector<int> dequeueCat() {
    if (catQueue_.empty()) return {-1, -1};
    vector<int> cat = catQueue_.front();
    catQueue_.pop();
    return cat;
  }

  queue<vector<int>> catQueue_;
  queue<vector<int>> dogQueue_;
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

#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 16m 9s
 * @brief 30m 55s
 * @brief 6m 7s
 * @brief 9m 31s
 *
 */
class AnimalShelf {
 public:
  AnimalShelf() : cats(), dogs() {}

  void enqueue(vector<int> animal) {
    if (animal[1] == 0) cats.push(animal[0]);
    if (animal[1] == 1) dogs.push(animal[0]);
  }

  vector<int> dequeueAny() {
    if (cats.empty()) return dequeueDog();
    if (dogs.empty()) return dequeueCat();

    int dog = dogs.front();
    int cat = cats.front();

    if (cat < dog) return dequeueCat();
    return dequeueDog();
  }

  vector<int> dequeueDog() {
    if (dogs.empty()) return {-1, -1};
    int dog = dogs.front();
    dogs.pop();
    return {dog, 1};
  }

  vector<int> dequeueCat() {
    if (cats.empty()) return {-1, -1};
    int cat = cats.front();
    cats.pop();
    return {cat, 0};
  }

  queue<int> cats;
  queue<int> dogs;
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

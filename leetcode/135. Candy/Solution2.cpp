#include <numeric>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 19 m 44 s
 * O(n)
 * 貪心兩次
 */
class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();

    vector<int> candies(n, 1);

    for (size_t i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1]) {
        candies[i] = candies[i - 1] + 1;
      }
    }

    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        if (candies[i + 1] + 1 > candies[i]) {
          candies[i] = candies[i + 1] + 1;
        }
      }
    }

    return accumulate(candies.begin(), candies.end(), 0);
  }
};

int main() {
  Solution s;

  vector<int> s2 = {1, 2, 87, 87, 87, 2, 1};
  s.candy(s2);

  vector<int> s1 = {1, 0, 2};
  s.candy(s1);
}

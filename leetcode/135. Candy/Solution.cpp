#include <numeric>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 19 m 44 s
 * O(n)
 */
class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();

    vector<int> candies(n, 1);

    int left = 0;
    for (int i = 0; i < n; i++) {
      if (i - 1 >= 0 && ratings[i] > ratings[i - 1]) {
        candies[i] = candies[i - 1] + 1;
      }

      if ((i + 1 < n && ratings[i] <= ratings[i + 1]) || (i + 1 == n)) {
        for (int j = i - 1; j >= left; j--) {
          candies[j] = max(candies[j], candies[j + 1] + 1);
        }

        left = i + 1;
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

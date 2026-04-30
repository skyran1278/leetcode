#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief -- (editorial)
 * @brief 9m 23s (recall)
 * @brief 7m 30s (recall)
 * O(log(maxValue))
 * O(1)
 */
class Solution {
 public:
  int nthUglyNumber(int n, int a, int b, int c) {
    using ll = long long;

    auto lcm = [](ll x, ll y) -> ll {
      ll g = std::gcd(x, y);
      return x / g * y;
    };

    ll ab = lcm(a, b);
    ll ac = lcm(a, c);
    ll bc = lcm(b, c);
    ll abc = lcm(ab, c);

    auto count = [&](ll x) -> ll {
      return x / a + x / b + x / c - x / ab - x / ac - x / bc + x / abc;
    };

    ll low = 1;
    ll high = 2e9;
    while (high > low) {
      ll mid = low + (high - low) / 2;
      if (count(mid) >= n) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return static_cast<int>(low);
  }
};

int main() {
  Solution s;
  s.nthUglyNumber(5, 2, 3, 5);
}

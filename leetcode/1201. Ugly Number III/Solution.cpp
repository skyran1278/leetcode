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
 * O(log(maxValue))
 * O(1)
 */
class Solution {
 public:
  int nthUglyNumber(int n, int a, int b, int c) {
    using ll = long long;

    auto lcm = [](ll x, ll y) -> ll {
      ll g = __gcd(x, y);
      // clamp overflow: if result > 2e18, treat as infinity
      return (x / g > 2e18 / y) ? (ll)2e18 : x / g * y;
    };

    ll ab = lcm(a, b);
    ll bc = lcm(b, c);
    ll ac = lcm(a, c);
    ll abc = lcm(ab, c);

    // count ugly numbers in [1, x]
    auto count = [&](ll x) -> ll {
      return x / a + x / b + x / c - x / ab - x / bc - x / ac + x / abc;
    };

    ll lo = 1, hi = 2e9;
    while (lo < hi) {
      ll mid = lo + (hi - lo) / 2;
      if (count(mid) >= n)
        hi = mid;
      else
        lo = mid + 1;
    }
    return (int)lo;
  }
};

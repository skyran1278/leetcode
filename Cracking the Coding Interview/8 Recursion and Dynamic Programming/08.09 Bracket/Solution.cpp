#include <algorithm>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 5 m 55 s
 * O(n * Cn) where Cn is the n-th Catalan number
 * O(n)
 */
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string state;
    backtrack(result, state, n * 2, n, n);
    return result;
  }

  void backtrack(vector<string>& result, string& state, int n, int left,
                 int right) {
    if (state.size() == n) {
      result.push_back(state);
      return;
    }

    if (left > 0) {
      state.push_back('(');
      backtrack(result, state, n, left - 1, right);
      state.pop_back();
    }

    if (right > left) {
      state.push_back(')');
      backtrack(result, state, n, left, right - 1);
      state.pop_back();
    }
  }
};

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
 * @brief 5m 55s
 * @brief 46m 46s
 * O(n * Cn) where Cn is the n-th Catalan number
 * O(n)
 */
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result{};
    string state{};
    backtrack(n, n, state, result);
    return result;
  }

  void backtrack(int open, int close, string& state, vector<string>& result) {
    if (open == 0 && close == 0) {
      result.push_back(state);
      return;
    }

    if (open > 0) {
      state.push_back('(');
      backtrack(open - 1, close, state, result);
      state.pop_back();
    }

    if (close > open) {
      state.push_back(')');
      backtrack(open, close - 1, state, result);
      state.pop_back();
    }
  }
};

int main() {
  Solution s;
  s.generateParenthesis(2);
  return 0;
}

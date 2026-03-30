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
 * @brief 10m 4s
 * @brief 3m 18s
 * @brief 6m 57s
 * O(n * n!)
 * O(n) without output
 */
class Solution {
 public:
  vector<string> permutation(string S) {
    vector<string> result{};
    string state{};
    vector<bool> used(S.size(), false);
    backtrack(S, used, state, result);
    return result;
  }

  void backtrack(const string& S, vector<bool>& used, string& state,
                 vector<string>& result) {
    if (state.size() == S.size()) {
      result.push_back(state);
      return;
    }

    for (size_t i = 0; i < S.size(); ++i) {
      if (used[i]) continue;

      used[i] = true;
      state.push_back(S[i]);
      backtrack(S, used, state, result);
      state.pop_back();
      used[i] = false;
    }
  }
};

int main() {
  Solution s;
  s.permutation("abc");
}

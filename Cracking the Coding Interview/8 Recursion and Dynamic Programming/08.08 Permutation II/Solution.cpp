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
 * @brief 22 m 33 s
 * O(n! * n)
 * O(n)
 */
class Solution {
 public:
  vector<string> permutation(string S) {
    vector<string> result;
    size_t n = S.size();
    string state;
    vector<bool> visited(n);
    sort(S.begin(), S.end());
    backtrack(result, n, state, visited, S);
    return result;
  }

  void backtrack(vector<string>& result, size_t n, string& state,
                 vector<bool>& visited, string& S) {
    if (state.size() == n) {
      result.push_back(state);
      return;
    }

    for (size_t i = 0; i < n; i++) {
      if (visited[i]) continue;
      if (i > 0 && S[i] == S[i - 1] && !visited[i - 1]) continue;
      visited[i] = true;
      state.push_back(S[i]);
      backtrack(result, n, state, visited, S);
      visited[i] = false;
      state.pop_back();
    }
  }
};

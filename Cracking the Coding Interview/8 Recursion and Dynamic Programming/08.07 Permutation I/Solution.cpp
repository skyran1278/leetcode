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
 * @brief 10 m 4 s
 * O(n * n!)
 * O(n) without output
 */
class Solution {
 public:
  vector<string> permutation(string S) {
    vector<string> result;
    size_t n = S.size();
    string state;
    vector<bool> visited(n);
    backtrack(result, n, state, visited, S);
    return result;
  }

  void backtrack(vector<string>& result, size_t n, string& state,
                 vector<bool>& visited, string S) {
    if (state.size() == n) {
      result.push_back(state);
      return;
    }

    for (size_t i = 0; i < n; i++) {
      if (visited[i]) continue;

      visited[i] = true;
      state.push_back(S[i]);
      backtrack(result, n, state, visited, S);
      visited[i] = false;
      state.pop_back();
    }
  }
};

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
 * @brief 17 m 2 s
 * O(n!)
 * O(n)
 */
class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> state;
    int row = 0;
    vector<bool> usedCol(n);
    vector<bool> usedDiag1(2 * n);
    vector<bool> usedDiag2(2 * n);

    backtrack(result, n, state, row, usedCol, usedDiag1, usedDiag2);

    return result;
  }

  void backtrack(vector<vector<string>>& result, int n, vector<string>& state,
                 int row, vector<bool>& usedCol, vector<bool>& usedDiag1,
                 vector<bool>& usedDiag2) {
    if (row == n) {
      result.push_back(state);
      return;
    }

    for (int col = 0; col < n; col++) {
      int diag1 = row - col + (n - 1);
      int diag2 = row + col;

      if (usedCol[col] || usedDiag1[diag1] || usedDiag2[diag2]) continue;

      usedCol[col] = usedDiag1[diag1] = usedDiag2[diag2] = true;
      string s(n, '.');
      s[col] = 'Q';
      state.push_back(s);

      backtrack(result, n, state, row + 1, usedCol, usedDiag1, usedDiag2);

      usedCol[col] = usedDiag1[diag1] = usedDiag2[diag2] = false;
      state.pop_back();
    }
  }
};

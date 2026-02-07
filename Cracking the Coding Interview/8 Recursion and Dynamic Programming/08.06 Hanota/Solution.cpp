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
 * @brief 3 m 41 s
 * @brief 3 m 34 s
 * O(2^n)
 * O(n)
 */
class Solution {
 public:
  void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
    dfs(A.size(), A, B, C);
  }

  void dfs(size_t n, vector<int>& A, vector<int>& B, vector<int>& C) {
    if (n == 1) {
      move(A, C);
      return;
    }

    dfs(n - 1, A, C, B);
    move(A, C);
    dfs(n - 1, B, A, C);
  }

  void move(vector<int>& A, vector<int>& B) {
    B.push_back(A.back());
    A.pop_back();
  }
};

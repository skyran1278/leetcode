#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/**
 * @brief 1 hrs 15 m 12 s
 *
 */
class Solution {
 public:
  vector<vector<int>> BSTSequences(TreeNode *root) {
    if (root == nullptr) {
      return {{}};
    }

    vector<vector<int>> leftSequences = BSTSequences(root->left);
    vector<vector<int>> rightSequences = BSTSequences(root->right);

    vector<vector<int>> results;
    for (auto &&lefts : leftSequences) {
      for (auto &&rights : rightSequences) {
        vector<int> state = {root->val};
        backtrack(lefts, 0, rights, 0, state, results);
      }
    }

    return results;
  }

 private:
  void backtrack(vector<int> &lefts, int leftIndex, vector<int> &rights,
                 int rightIndex, vector<int> &state,
                 vector<vector<int>> &results) {
    if (leftIndex == lefts.size() || rightIndex == rights.size()) {
      vector<int> result = state;
      result.insert(result.end(), lefts.begin() + leftIndex, lefts.end());
      result.insert(result.end(), rights.begin() + rightIndex, rights.end());
      results.emplace_back(result);
      return;
    }

    int left = lefts[leftIndex];
    state.emplace_back(left);
    backtrack(lefts, leftIndex + 1, rights, rightIndex, state, results);
    state.pop_back();

    int right = rights[rightIndex];
    state.emplace_back(right);
    backtrack(lefts, leftIndex, rights, rightIndex + 1, state, results);
    state.pop_back();
  }
};

int main() {
  Solution s;

  TreeNode *node = new TreeNode(2);
  node->left = new TreeNode(1);
  node->right = new TreeNode(3);
  s.BSTSequences(node);
}

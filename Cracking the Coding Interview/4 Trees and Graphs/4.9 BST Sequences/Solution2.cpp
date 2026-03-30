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
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

/**
 * @brief 28m 8s
 * @brief 5m 41s
 * @brief 6m 16s
 * @brief 32m 18s
 * @brief 27m 27s
 * @brief 27m 53s
 * backtrack
 * O(n!)
 * O(n * n!)
 */
class Solution {
 public:
  vector<vector<int>> BSTSequences(TreeNode* root) {
    if (root == nullptr) return {{}};

    vector<vector<int>> result;
    vector<int> path;
    deque<TreeNode*> choices{root};
    backtrack(choices, path, result);

    return result;
  }

  void backtrack(deque<TreeNode*>& choices, vector<int>& state,
                 vector<vector<int>>& result) {
    if (choices.empty()) {
      result.emplace_back(state);
    }

    size_t size = choices.size();
    for (size_t i = 0; i < size; i++) {
      TreeNode* choice = choices.front();
      choices.pop_front();
      state.push_back(choice->val);
      if (choice->left != nullptr) choices.push_back(choice->left);
      if (choice->right != nullptr) choices.push_back(choice->right);

      backtrack(choices, state, result);

      if (choice->left != nullptr) choices.pop_back();
      if (choice->right != nullptr) choices.pop_back();
      state.pop_back();
      choices.push_back(choice);
    }
  }
};

int main() {
  Solution s;

  TreeNode* node = new TreeNode(2);
  node->left = new TreeNode(1);
  node->right = new TreeNode(3);
  s.BSTSequences(node);
}

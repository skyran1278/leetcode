#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

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
 * @brief 27 m 51 s
 * @brief 34 m 17 s
 * O(n^2)
 * O(n)
 */
class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    vector<int> state;

    if (root) backtrack(result, state, root, targetSum);

    return result;
  }

  void backtrack(vector<vector<int>>& result, vector<int>& state,
                 TreeNode* node, int targetSum) {
    targetSum -= node->val;
    state.push_back(node->val);

    if (node->left == nullptr && node->right == nullptr && targetSum == 0) {
      result.push_back(state);
    }

    if (node->left) backtrack(result, state, node->left, targetSum);
    if (node->right) backtrack(result, state, node->right, targetSum);

    state.pop_back();
  }
};

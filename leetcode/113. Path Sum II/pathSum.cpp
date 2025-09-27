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
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/**
 * @brief 27 m 7 s
 * O(n^2)
 * O(n)
 */
class Solution {
 public:
  vector<vector<int>> result;
  vector<int> state;

  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return {};
    }

    state.push_back(root->val);
    targetSum -= root->val;

    if (targetSum == 0 && root->left == nullptr && root->right == nullptr) {
      result.push_back(state);
    }

    pathSum(root->left, targetSum);
    pathSum(root->right, targetSum);

    state.pop_back();

    return result;
  }
};

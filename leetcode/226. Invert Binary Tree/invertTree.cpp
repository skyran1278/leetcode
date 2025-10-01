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
 * @brief 3 m 42 s
 * @brief 6 m 49 s
 * O(n)
 * O(h)
 */
class Solution {
 public:
  // root = [4,2,7,1,3,6,9]
  TreeNode *invertTree(TreeNode *root) {
    if (root != nullptr) {
      TreeNode *tmp = root->left;  // tmp = 2
      root->left = root->right;
      root->right = tmp;

      invertTree(root->left);
      invertTree(root->right);
    }

    return root;
  }
};

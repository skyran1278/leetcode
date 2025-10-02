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
 * @brief 17 m 58 s
 * @brief 10 m 2 s
 * O(n)
 * O(h)
 */
class Solution {
 public:
  // root = [1,2,2,3,4,4,3]
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;

    return isMirror(root->left, root->right);
  }

  bool isMirror(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) return true;

    if (left == nullptr || right == nullptr || left->val != right->val ||
        !isMirror(left->right, right->left) ||
        !isMirror(left->left, right->right)) {
      return false;
    }

    return true;
  }
};

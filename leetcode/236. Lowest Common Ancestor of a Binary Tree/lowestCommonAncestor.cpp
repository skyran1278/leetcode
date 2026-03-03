/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * @brief 1 hrs 7m 47s
 * @brief 14m 37s
 * @brief 4m 58s
 * O(n)
 * O(h) where h is the height of the tree (recursion stack). Worst case O(n) for
 * a skewed tree.
 */
class Solution {
 public:
  // root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
  // root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) {
      return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) {
      return root;
    }

    return left != nullptr ? left : right;
  }
};

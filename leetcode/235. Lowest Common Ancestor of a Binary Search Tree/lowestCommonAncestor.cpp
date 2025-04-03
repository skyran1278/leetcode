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
 * @brief 12 m 37 s
 *
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < q->val) return lowestCommonAncestor(root, q, p);

    while (true) {
      if (root->val > p->val) {
        root = root->left;
      } else if (root->val < q->val) {
        root = root->right;
      } else {
        return root;
      }
    }

    return nullptr;
  }
};

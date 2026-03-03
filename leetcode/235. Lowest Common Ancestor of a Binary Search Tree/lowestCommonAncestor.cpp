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
 * @brief 12m 37s
 * @brief 8m 42s
 * @brief 3m 8s
 * @brief 4m 50s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < q->val) return lowestCommonAncestor(root, q, p);

    while (root) {
      if (root->val > p->val) {
        root = root->left;
      } else if (root->val < q->val) {
        root = root->right;
      } else {
        break;
      }
    }

    return root;
  }
};

#include <stack>

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
 * @brief 15 m 56 s
 * O(n)
 * O(h)
 */
class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) { return inorder(root, k); }

  int inorder(TreeNode* node, int& k) {
    if (node == nullptr) return -1;

    int left = inorder(node->left, k);
    if (left != -1) return left;

    if (k == 1) return node->val;
    k--;

    int right = inorder(node->right, k);
    if (right != -1) return right;

    return -1;
  }
};

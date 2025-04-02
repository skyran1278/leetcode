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
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/**
 * @brief 11 m 6 s
 * O(n)
 */
class Solution {
 public:
  int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> kStack;
    while (true) {
      while (root != nullptr) {
        kStack.push(root);
        root = root->left;
      }

      root = kStack.top();
      kStack.pop();

      if (--k == 0) {
        return root->val;
      }

      root = root->right;
    }

    return -1;
  }
};

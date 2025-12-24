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
 * @brief 17 m 13 s
 * O(n)
 * O(h)
 */
class Solution {
 public:
  // root = [5,3,6,2,4,null,null,1], k = 3
  int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> kStack;

    while (root != nullptr || !kStack.empty()) {
      while (root != nullptr) {
        kStack.push(root);
        root = root->left;
      }
      // s = [5, 3, 2, 1]

      root = kStack.top();
      kStack.pop();
      // s = [5]

      if (--k == 0) {
        return root->val;
      }

      root = root->right;
    }

    return -1;
  }
};

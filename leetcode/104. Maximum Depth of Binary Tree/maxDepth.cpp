#include <algorithm>

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
 * @brief 16 m 55 s
 * O(n)
 */
class Solution {
 public:
  int maxDepth(TreeNode *root) { return backtrack(0, root); }

  int backtrack(int depth, TreeNode *node) {
    if (node == nullptr) {
      return depth;
    }

    int left = backtrack(depth + 1, node->left);
    int right = backtrack(depth + 1, node->right);

    return max(left, right);
  }
};

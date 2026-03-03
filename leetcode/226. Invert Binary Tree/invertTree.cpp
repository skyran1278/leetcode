#include <vector>

using namespace std;

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
 * @brief 3m 42s
 * @brief 6m 49s
 * @brief 2m 50s
 * O(n)
 * O(h)
 */
class Solution {
 public:
  // root = [4,2,7,1,3,6,9]
  TreeNode* invertTree(TreeNode* root) {
    if (root != nullptr) {
      swap(root->left, root->right);

      invertTree(root->left);
      invertTree(root->right);
    }

    return root;
  }
};

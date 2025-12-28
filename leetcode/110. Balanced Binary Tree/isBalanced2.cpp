#include <algorithm>

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
 * @brief 17 m 52 s
 * @brief 2 m 10 s
 * O(n)
 * O(h)
 */
class Solution {
 public:
  // root = [3,9,20,null,null,15,7]
  bool isBalanced(TreeNode* root) { return depth(root) != -1; }

  int depth(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }

    int left = depth(node->left);    // 1,
    int right = depth(node->right);  // 2

    if (left == -1 || right == -1 || abs(left - right) > 1) {
      return -1;
    }

    return max(left, right) + 1;
  }
};

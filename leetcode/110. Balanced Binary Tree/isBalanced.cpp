#include <algorithm>

using namespace std;

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
 * @brief 54 m 35 s
 * O(n^2)
 */
class Solution {
 public:
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) return true;

    int d = depth(root->left) - depth(root->right);

    if (d > 1 || d < -1) {
      return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
  }

 private:
  int depth(TreeNode *root) {
    if (root == nullptr) return 0;

    return max(depth(root->left), depth(root->right)) + 1;
  }
};

int main() {
  Solution s;

  TreeNode *node1 = new TreeNode(4);
  TreeNode *node2 = new TreeNode(4);
  TreeNode *node3 = new TreeNode(3, node1, node2);
  TreeNode *node4 = new TreeNode(3);
  TreeNode *node5 = new TreeNode(2, node3, node4);
  TreeNode *node6 = new TreeNode(2);
  TreeNode *node7 = new TreeNode(1, node5, node6);
  s.isBalanced(node7);
}

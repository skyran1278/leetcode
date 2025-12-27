#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
 * @brief 24 m 1 s
 * @brief 5 m 32 s
 * @brief 3 m 18 s
 */
class Solution {
 public:
  bool isBalanced(TreeNode* root) { return height(root) != -1; }

  int height(TreeNode* node) {
    if (node == nullptr) return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    if (leftHeight == -1 || rightHeight == -1 ||
        abs(leftHeight - rightHeight) > 1) {
      return -1;
    }

    return max(leftHeight, rightHeight) + 1;
  }
};

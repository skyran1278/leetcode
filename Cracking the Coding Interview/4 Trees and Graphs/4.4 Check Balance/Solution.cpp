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
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/**
 * @brief 24 m 1 s
 */
class Solution {
 public:
  bool isBalanced(TreeNode *root) { return dfs(root) != -1; }

  int dfs(TreeNode *node) {
    if (node == nullptr) return 0;

    int leftHeight = dfs(node->left);
    int rightHeight = dfs(node->right);

    if (leftHeight == -1 || rightHeight == -1 ||
        abs(leftHeight - rightHeight) > 1) {
      return -1;
    }

    return max(leftHeight, rightHeight) + 1;
  }
};

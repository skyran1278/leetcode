#include <climits>
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
 * @brief 1 hrs 45 m 44 s
 * O(n)
 */
class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    long last = LONG_MIN;
    return inOrder(root, last);
  }

 private:
  bool inOrder(TreeNode *node, long &last) {
    if (node == nullptr) {
      return true;
    }

    if (!inOrder(node->left, last)) {
      return false;
    }

    if (node->val <= last) {
      return false;
    }

    last = node->val;

    return inOrder(node->right, last);
  }
};

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
 * @brief 7 m 21 s
 * O(n)
 */
class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    long last = LONG_MIN;
    return inorder(root, last);
  }
  bool inorder(TreeNode *current, long &last) {
    if (current == nullptr) {
      return true;
    }

    long left = inorder(current->left, last);

    if (current->val <= last) {
      return false;
    }

    last = current->val;

    return left && inorder(current->right, last);
  }
};

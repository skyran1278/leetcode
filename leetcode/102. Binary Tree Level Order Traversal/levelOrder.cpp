#include <deque>
#include <vector>

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
 * @brief 36 m 9 s
 * O(n)
 */
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> levels = {};

    if (root == nullptr) {
      return levels;
    }

    deque<TreeNode *> nodes = {root};

    while (!nodes.empty()) {
      int n = nodes.size();
      vector<int> values = {};
      for (size_t i = 0; i < n; i++) {
        TreeNode *node = nodes.front();
        nodes.pop_front();

        values.push_back(node->val);

        if (node->left != nullptr) {
          nodes.push_back(node->left);
        }

        if (node->right != nullptr) {
          nodes.push_back(node->right);
        }
      }

      levels.push_back(values);
    }

    return levels;
  }
};

#include <queue>
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
 * @brief 12 m 50 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  // root = [3,9,20,null,null,15,7]
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> levels;

    queue<TreeNode *> nodes;
    if (root != nullptr) {
      nodes.push(root);
    }

    while (!nodes.empty()) {
      vector<int> values;

      size_t count = nodes.size();  // count = 2
      for (size_t i = 0; i < count; i++) {
        TreeNode *node = nodes.front();
        nodes.pop();

        values.push_back(node->val);  // level = [15, 7]

        if (node->left != nullptr) {
          nodes.push(node->left);
        }

        if (node->right != nullptr) {
          nodes.push(node->right);
        }
      }

      levels.push_back(values);  // result = [[3], [9, 20], [15, 7]]
    }

    return levels;
  }
};

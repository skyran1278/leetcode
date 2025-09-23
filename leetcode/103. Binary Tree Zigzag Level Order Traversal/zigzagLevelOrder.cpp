#include <algorithm>
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
 * @brief 13 m 45 s
 * @brief 13 m 48 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  // root = [3,9,20,null,null,15,7]
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> levels;

    queue<TreeNode *> nodes;
    if (root != nullptr) {
      nodes.push(root);
    }
    // nodes = [3]

    bool isReverse = false;
    while (!nodes.empty()) {
      vector<int> values;

      size_t count = nodes.size();
      for (size_t i = 0; i < count; i++) {
        TreeNode *node = nodes.front();
        nodes.pop();

        values.push_back(node->val);

        if (node->left != nullptr) {
          nodes.push(node->left);
        }
        if (node->right != nullptr) {
          nodes.push(node->right);
        }
      }
      // nodes = [15, 7]

      if (isReverse) {
        reverse(values.begin(), values.end());
      }

      isReverse = !isReverse;

      levels.push_back(values);  // levels = [[3], [20, 9]]
    }

    return levels;
  }
};

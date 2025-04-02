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
 * @brief 13 m 45 s
 * O(n)
 */
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> levels = {};

    if (root == nullptr) {
      return {};
    }

    deque<TreeNode *> nodes = {root};
    bool asc = true;
    while (!nodes.empty()) {
      vector<int> values = {};
      size_t levelSize = nodes.size();
      for (size_t i = 0; i < levelSize; i++) {
        if (asc) {
          TreeNode *node = nodes.front();
          nodes.pop_front();

          values.push_back(node->val);

          if (node->left != nullptr) {
            nodes.push_back(node->left);
          }

          if (node->right != nullptr) {
            nodes.push_back(node->right);
          }
        } else {
          TreeNode *node = nodes.back();
          nodes.pop_back();

          values.push_back(node->val);

          if (node->right != nullptr) {
            nodes.push_front(node->right);
          }

          if (node->left != nullptr) {
            nodes.push_front(node->left);
          }
        }
      }

      asc = !asc;

      levels.push_back(values);
    }

    return levels;
  }
};

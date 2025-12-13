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
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

/**
 * @brief 22 m 53 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;

    queue<TreeNode*> nodes;
    if (root) nodes.push(root);

    bool reverse = false;
    while (!nodes.empty()) {
      deque<int> values;

      size_t count = nodes.size();
      for (size_t i = 0; i < count; i++) {
        TreeNode* node = nodes.front();
        nodes.pop();

        if (reverse) {
          values.push_front(node->val);
        } else {
          values.push_back(node->val);
        }

        if (node->left) nodes.push(node->left);
        if (node->right) nodes.push(node->right);
      }

      result.emplace_back(values.begin(), values.end());
      reverse = !reverse;
    }

    return result;
  }
};

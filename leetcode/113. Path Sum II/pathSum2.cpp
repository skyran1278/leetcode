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
 * @brief 27 m 51 s
 * O(n^2)
 * O(n)
 */
class Solution {
 public:
  // root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> result;
    vector<int> state;

    if (root != nullptr) {
      state.push_back(root->val);                             // state = [5]
      backtrack(root, state, targetSum - root->val, result);  // targetSum = 17
    }

    return result;
  }

  void backtrack(TreeNode *node, vector<int> &state, int targetSum,
                 vector<vector<int>> &result) {
    if (node->left == nullptr && node->right == nullptr && targetSum == 0) {
      result.push_back(state);
      return;
    }

    for (auto &&choice : {node->left, node->right}) {
      if (choice != nullptr) {
        state.push_back(choice->val);  // state = [5, 4, 11, 2]
        backtrack(choice, state, targetSum - choice->val,
                  result);  // targetSum = 2, -5, 0
        state.pop_back();
      }
    }
  }
};

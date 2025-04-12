#include <algorithm>
#include <unordered_map>
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
 * @brief 18 m 26 s
 * O(n)
 */
class Solution {
 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (size_t i = 0; i < inorder.size(); i++) {
      inorderMap[inorder[i]] = i;
    }

    return _buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
  }

 private:
  unordered_map<int, int> inorderMap;

  TreeNode *_buildTree(vector<int> &preorder, vector<int> &inorder,
                       int preorderLeft, int preorderRight, int inorderLeft,
                       int inorderRight) {
    if (preorderLeft == preorderRight) return nullptr;

    int rootValue = preorder[preorderLeft];

    int rootIndex = inorderMap[rootValue];
    int leftCount = rootIndex - inorderLeft;

    TreeNode *root = new TreeNode(rootValue);

    root->left =
        _buildTree(preorder, inorder, preorderLeft + 1,
                   preorderLeft + 1 + leftCount, inorderLeft, rootIndex);
    root->right = _buildTree(preorder, inorder, preorderLeft + 1 + leftCount,
                             preorderRight, rootIndex + 1, inorderRight);

    return root;
  }
};

int main() {
  Solution s;
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};
  s.buildTree(preorder, inorder);
}

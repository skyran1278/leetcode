#include <unordered_map>
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
 * @brief 18 m 26 s
 * @brief 34 m 6 s
 * O(n)
 * O(n) recursion stack + hashmap
 */
class Solution {
 public:
  // preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (size_t i = 0; i < inorder.size(); i++) {
      inorderMap_[inorder[i]] = i;
    }

    return _buildTree(preorder, inorder, 0, 0, preorder.size());
  }

 private:
  unordered_map<int, int> inorderMap_;

  // preIdx = 0, inIdx = 0, count = 5
  // preIdx = 1, inIdx = 0, count = 1
  // preIdx = 2, inIdx = 2, count = 3
  TreeNode *_buildTree(vector<int> &preorder, vector<int> &inorder,
                       size_t preIdx, size_t inIdx, int count) {
    if (count <= 0) {
      return nullptr;
    }

    int rootValue = preorder[preIdx];
    int rootIndex = inorderMap_[rootValue];

    int leftCount = rootIndex - inIdx;
    int rightCount = count - leftCount - 1;

    TreeNode *root = new TreeNode(rootValue);
    root->left = _buildTree(preorder, inorder, preIdx + 1, inIdx, leftCount);
    root->right = _buildTree(preorder, inorder, preIdx + 1 + leftCount,
                             rootIndex + 1, rightCount);

    return root;
  }
};

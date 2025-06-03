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
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief 1 hrs 5 m 13 s
 *
 */
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* previous = nullptr;
    return inorder(root, p, previous);
  }

  TreeNode* inorder(TreeNode* root, TreeNode* p, TreeNode*& previous) {
    if (root == nullptr) {
      return nullptr;
    }

    TreeNode* left = inorder(root->left, p, previous);
    if (left != nullptr) {
      return left;
    }

    if (previous == p) {
      return root;
    }

    previous = root;

    TreeNode* right = inorder(root->right, p, previous);
    if (right != nullptr) {
      return right;
    }

    return nullptr;
  }
};

int main() {
  Solution s;

  //   TreeNode* node = new TreeNode(2);
  //   node->left = new TreeNode(1);
  //   node->right = new TreeNode(3);
  //   s.inorderSuccessor(node, node->left);

  TreeNode* node = new TreeNode(2);
  node->right = new TreeNode(3);
  s.inorderSuccessor(node, node);
}

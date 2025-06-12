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
 * @brief 46 m 35 s
 * @brief 13 m
 * dfs
 * O(n)
 * O(h)
 */
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* previous = nullptr;
    TreeNode* successor = nullptr;
    inorder(root, p, previous, successor);
    return successor;
  }

  void inorder(TreeNode* current, TreeNode* target, TreeNode*& previous,
               TreeNode*& successor) {
    if (current == nullptr || successor != nullptr) {
      return;
    }

    inorder(current->left, target, previous, successor);

    if (previous == target) {
      successor = current;
    }

    previous = current;

    inorder(current->right, target, previous, successor);
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

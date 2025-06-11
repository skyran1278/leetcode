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
 * dfs
 * O(n)
 * O(h)
 */
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = nullptr;
    TreeNode* previous = nullptr;
    inorder(root, previous, successor, p);
    return successor;
  }

  void inorder(TreeNode* current, TreeNode*& previous, TreeNode*& successor,
               TreeNode* target) {
    if (current == nullptr || successor != nullptr) {
      return;
    }

    inorder(current->left, previous, successor, target);

    if (previous == target) {
      successor = current;
    }

    previous = current;

    inorder(current->right, previous, successor, target);
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

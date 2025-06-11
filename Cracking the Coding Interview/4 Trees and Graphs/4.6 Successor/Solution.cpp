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
 * @brief 8 m 1 s
 * O(h) h = tree height
 * O(1)
 */
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = nullptr;

    while (root != nullptr) {
      if (root->val > p->val) {
        successor = root;
        root = root->left;
      } else {
        root = root->right;
      }
    }

    return successor;
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

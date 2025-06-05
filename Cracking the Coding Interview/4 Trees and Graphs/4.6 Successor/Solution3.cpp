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
 * dfs stack
 * O(h) h = tree height
 * O(h)
 */
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    stack<TreeNode*> s;

    TreeNode* previous = nullptr;
    TreeNode* current = root;
    while (!s.empty() || current != nullptr) {
      while (current != nullptr) {
        s.push(current);
        current = current->left;
      }

      current = s.top();
      s.pop();

      if (previous == p) {
        return current;
      }

      previous = current;

      current = current->right;
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

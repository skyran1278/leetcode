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

// O(h) time, O(1) space  (h = tree height)
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* succ = nullptr;

    while (root) {
      if (p->val < root->val) {
        // Current node is a candidate; go left to find a smaller one
        succ = root;
        root = root->left;
      } else {
        // Successor must be on the right
        root = root->right;
      }
    }
    return succ;
  }
};

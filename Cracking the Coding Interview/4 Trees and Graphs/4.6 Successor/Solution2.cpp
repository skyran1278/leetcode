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

// O(n) time, O(h) space
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* prev = nullptr;  // last visited node
    TreeNode* succ = nullptr;  // answer to return
    inorder(root, p, prev, succ);
    return succ;
  }

 private:
  void inorder(TreeNode* node, TreeNode* target, TreeNode*& prev,
               TreeNode*& succ) {
    if (!node || succ) return;  // early exit if found

    inorder(node->left, target, prev, succ);

    if (prev == target) succ = node;  // first node after target
    prev = node;

    inorder(node->right, target, prev, succ);
  }
};

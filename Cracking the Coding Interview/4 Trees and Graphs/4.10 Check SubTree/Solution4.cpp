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
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

/**
 * @brief 48 m 19 s
 * O(mn)
 * O(h)
 */
class Solution {
 public:
  bool checkSubTree(TreeNode* t1, TreeNode* t2) {
    int t2Height = height(t2);

    return checkSubTree_(t1, t2, t2Height) == -1;
  }

  int checkSubTree_(TreeNode* t1, TreeNode* t2, int t2Height) {
    if (t1 == nullptr) return 0;

    int left = checkSubTree_(t1->left, t2, t2Height);
    int right = checkSubTree_(t1->right, t2, t2Height);
    if (left == -1 || right == -1) return -1;

    int t1Hight = max(left, right) + 1;

    if (t1Hight == t2Height && isSame(t1, t2)) return -1;

    return t1Hight;
  }

  int height(TreeNode* node) {
    if (node == nullptr) return 0;
    return max(height(node->left), height(node->right)) + 1;
  }

  int isSame(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;
    return t1->val == t2->val && isSame(t1->left, t2->left) &&
           isSame(t1->right, t2->right);
  }
};

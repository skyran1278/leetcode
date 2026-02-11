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
 * @brief 10 m 14 s
 * @brief 10 m 10 s
 * n = number of nodes in T1, m = number of nodes in T2
 * O(nm)
 * O(max(n, m))
 */
class Solution {
 public:
  bool checkSubTree(TreeNode* t1, TreeNode* t2) {
    int t2Hight = height(t2);
    int t1Hight = height(t1);

    if (t1Hight == t2Hight && isSameTree(t1, t2)) {
      return true;
    }

    if (t1Hight > t2Hight) {
      return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }

    return false;
  }

  bool isSameTree(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) {
      return true;
    }

    if (t1 == nullptr || t2 == nullptr) {
      return false;
    }

    return t1->val == t2->val && isSameTree(t1->left, t2->left) &&
           isSameTree(t1->right, t2->right);
  }

  int height(TreeNode* tree) {
    if (tree == nullptr) {
      return 0;
    }

    return max(height(tree->left), height(tree->right)) + 1;
  }
};

int main() {
  Solution s;

  TreeNode* t1 = new TreeNode(1);
  t1->left = new TreeNode(2);
  t1->right = new TreeNode(3);
  TreeNode* t2 = new TreeNode(2);
  s.checkSubTree(t1, t2);
}

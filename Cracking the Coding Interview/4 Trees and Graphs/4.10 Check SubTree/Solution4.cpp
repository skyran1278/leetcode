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
 * @brief 17 m 54 s
 * Height check skips isSame unless exact match, better than naive O(NM) always
 * n = number of nodes in T1, m = number of nodes in T2
 * O(nm)
 * O(max(n, m))
 */
class Solution {
 public:
  bool checkSubTree(TreeNode* t1, TreeNode* t2) {
    int t1Height = 0;
    int t2Height = height(t2);
    bool result = false;
    checkSubTreeWithSameHeight(t1, t2, t1Height, t2Height, result);
    return result;
  }

  void checkSubTreeWithSameHeight(TreeNode* t1, TreeNode* t2, int& t1Height,
                                  int t2Height, bool& result) {
    if (result) return;
    if (t1 == nullptr) return;

    int left = 0;
    checkSubTreeWithSameHeight(t1->left, t2, left, t2Height, result);
    int right = 0;
    checkSubTreeWithSameHeight(t1->right, t2, right, t2Height, result);
    t1Height = max(left, right) + 1;

    if (t1Height == t2Height && isSame(t1, t2)) {
      result = true;
      return;
    }
  }

  bool isSame(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;

    return t1->val == t2->val && isSame(t1->left, t2->left) &&
           isSame(t1->right, t2->right);
  }

  int height(TreeNode* t) {
    if (t == nullptr) return 0;

    int left = height(t->left);
    int right = height(t->right);

    return max(left, right) + 1;
  }
};

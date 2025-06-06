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
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/**
 * @brief 25 m 23 s
 * bfs + dfs
 * n = number of nodes in T1, m = number of nodes in T2
 * O(nm)
 * O(max(n, m))
 */
class Solution {
 public:
  bool checkSubTree(TreeNode *t1, TreeNode *t2) {
    queue<TreeNode *> q;
    q.push(t1);

    while (!q.empty()) {
      int size = q.size();

      for (size_t i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();

        if (node->val == t2->val && isSameTree(node, t2)) {
          return true;
        }

        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
      }
    }

    return false;
  }

  bool isSameTree(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr && t2 == nullptr) {
      return true;
    }

    if (t1 == nullptr || t2 == nullptr || t1->val != t2->val) {
      return false;
    }

    return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
  }
};

int main() {
  Solution s;

  TreeNode *t1 = new TreeNode(1);
  t1->left = new TreeNode(2);
  t1->right = new TreeNode(3);
  TreeNode *t2 = new TreeNode(2);
  s.checkSubTree(t1, t2);
}

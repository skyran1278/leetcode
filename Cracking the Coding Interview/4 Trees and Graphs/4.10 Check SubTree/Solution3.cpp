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
 * @brief 3 m 29 s
 * @brief 4 m 21 s
 * n = number of nodes in T1, m = number of nodes in T2
 * O(m + n)
 * O(m + n)
 */
class Solution {
 public:
  bool checkSubTree(TreeNode* t1, TreeNode* t2) {
    string s1 = preOrder(t1);
    string s2 = preOrder(t2);

    return s1.find(s2) != string::npos;
  }

 private:
  string preOrder(TreeNode* tree) {
    string result;

    if (tree == nullptr) {
      result.append("X ");
      return result;
    }

    result.append("#" + to_string(tree->val) + " ");
    result.append(preOrder(tree->left));
    result.append(preOrder(tree->right));

    return result;
  }
};

int main() {
  Solution s;

  TreeNode* t1 = new TreeNode(21);
  t1->left = new TreeNode(1232);
  t1->right = new TreeNode(32);
  TreeNode* t2 = new TreeNode(2);
  s.checkSubTree(t1, t2);
}

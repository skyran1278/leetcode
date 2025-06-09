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
 * @brief 50 m 40 s
 * O(n^2)
 */
class Solution {
 public:
  int pathSum(TreeNode *root, int sum) {
    int result = 0;
    int left = sum;
    backtrack(result, left, false, root);
    return result;
  }

  void backtrack(int &result, int current, bool hasSelect, TreeNode *choice) {
    if (choice == nullptr) {
      return;
    }

    int minusNode = current - choice->val;
    if (minusNode == 0) {
      result += 1;
    }

    if (!hasSelect) {
      backtrack(result, current, hasSelect, choice->left);
      backtrack(result, current, hasSelect, choice->right);
    }

    backtrack(result, minusNode, true, choice->left);
    backtrack(result, minusNode, true, choice->right);
  }
};

int main() {
  Solution s;

  TreeNode *node = new TreeNode(1);
  s.pathSum(node, 0);
}

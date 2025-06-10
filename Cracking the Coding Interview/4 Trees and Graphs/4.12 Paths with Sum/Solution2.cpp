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
 * @brief 14 m 50 s
 * @brief 32 m 35 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  int pathSum(TreeNode *root, int sum) {
    int result = 0;
    unordered_map<int, int> prefix;
    prefix[0] = 1;
    backtrack(result, prefix, 0, sum, root);
    return result;
  }

  void backtrack(int &result, unordered_map<int, int> &prefix, int current,
                 int sum, TreeNode *choice) {
    if (choice == nullptr) {
      return;
    }

    current += choice->val;
    if (prefix.count(current - sum)) {
      result += prefix[current - sum];
    }

    prefix[current]++;
    backtrack(result, prefix, current, sum, choice->left);
    backtrack(result, prefix, current, sum, choice->right);
    prefix[current]--;
  }
};

int main() {
  Solution s;

  TreeNode *node = new TreeNode(0);
  node->left = new TreeNode(1);
  node->right = new TreeNode(1);
  s.pathSum(node, 1);
}

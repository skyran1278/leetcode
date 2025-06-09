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
 * O(n)
 * O(n)
 */
class Solution {
 public:
  int pathSum(TreeNode *root, int sum) {
    int result = 0;
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;

    backtrack(result, prefixSum, 0, sum, root);

    return result;
  }

  void backtrack(int &result, unordered_map<int, int> &prefixSum, int current,
                 int sum, TreeNode *choice) {
    if (choice == nullptr) {
      return;
    }

    current += choice->val;

    int prefix = current - sum;
    if (prefixSum.count(prefix)) {
      result += prefixSum[prefix];
    }

    prefixSum[current]++;

    backtrack(result, prefixSum, current, sum, choice->left);
    backtrack(result, prefixSum, current, sum, choice->right);

    prefixSum[current]--;
  }
};

int main() {
  Solution s;

  TreeNode *node = new TreeNode(0);
  node->left = new TreeNode(1);
  node->right = new TreeNode(1);
  s.pathSum(node, 1);
}

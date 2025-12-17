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
 * @brief 15 m 4 s
 * @brief 16 m 56 s
 * O(n)
 * O(logn)
 */
class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfs(nums, 0, nums.size());
  }

  TreeNode* dfs(vector<int>& nums, int left, int right) {
    if (left >= right) {
      return nullptr;
    }

    int index = left + (right - left) / 2;

    TreeNode* node = new TreeNode(nums[index]);
    node->left = dfs(nums, left, index);
    node->right = dfs(nums, index + 1, right);
    return node;
  }
};

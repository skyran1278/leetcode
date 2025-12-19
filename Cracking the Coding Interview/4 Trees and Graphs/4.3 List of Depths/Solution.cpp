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

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * @brief 7 m 30 s
 * @brief 8 m 56 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  vector<ListNode*> listOfDepth(TreeNode* tree) {
    vector<ListNode*> result;

    queue<TreeNode*> q;
    if (tree) q.push(tree);

    while (!q.empty()) {
      size_t count = q.size();

      ListNode* dummy = new ListNode();
      ListNode* runner = dummy;
      for (size_t i = 0; i < count; i++) {
        TreeNode* node = q.front();
        q.pop();

        runner->next = new ListNode(node->val);
        runner = runner->next;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }

      result.push_back(dummy->next);
    }

    return result;
  }
};

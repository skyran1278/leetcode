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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * @brief 7 m 30 s
 * O(n)
 */
class Solution {
 public:
  vector<ListNode *> listOfDepth(TreeNode *tree) {
    vector<ListNode *> results;

    queue<TreeNode *> q;
    q.push(tree);

    while (!q.empty()) {
      int qSize = q.size();

      ListNode *level = new ListNode();
      ListNode *current = level;
      for (size_t i = 0; i < qSize; i++) {
        TreeNode *node = q.front();
        q.pop();

        ListNode *l = new ListNode(node->val);
        current->next = l;
        current = current->next;

        if (node->left != nullptr) {
          q.push(node->left);
        }

        if (node->right != nullptr) {
          q.push(node->right);
        }
      }

      results.push_back(level->next);
    }

    return results;
  }
};

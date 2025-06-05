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
 * @brief 28 m 8 s
 *
 */
class Solution {
 public:
  vector<vector<int>> BSTSequences(TreeNode *root) {
    if (root == nullptr) {
      return {{}};
    }

    vector<vector<int>> results;
    vector<int> path;
    deque<TreeNode *> choices = {root};
    backtrack(results, path, choices);
    return results;
  }

  void backtrack(vector<vector<int>> &results, vector<int> &path,
                 deque<TreeNode *> &choices) {
    if (choices.empty()) {
      results.emplace_back(path);
      return;
    }

    int choicesSize = choices.size();
    for (size_t i = 0; i < choicesSize; i++) {
      TreeNode *choice = choices.front();

      choices.pop_front();
      path.emplace_back(choice->val);
      if (choice->left != nullptr) {
        choices.push_back(choice->left);
      }
      if (choice->right != nullptr) {
        choices.push_back(choice->right);
      }

      backtrack(results, path, choices);

      if (choice->left != nullptr) {
        choices.pop_back();
      }
      if (choice->right != nullptr) {
        choices.pop_back();
      }
      path.pop_back();
      choices.push_back(choice);
    }
  }
};

int main() {
  Solution s;

  TreeNode *node = new TreeNode(2);
  node->left = new TreeNode(1);
  node->right = new TreeNode(3);
  s.BSTSequences(node);
}

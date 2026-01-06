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
 * @brief 28 m 8 s
 * @brief 5 m 41 s
 * @brief 6 m 16 s
 * @brief 32 m 18 s
 * @brief 27 m 27 s
 * backtrack
 * O(n!)
 * O(n * n!)
 */
class Solution {
 public:
  vector<vector<int>> BSTSequences(TreeNode* root) {
    if (root == nullptr) return {{}};

    vector<vector<int>> possibleArrays;
    vector<int> path;
    deque<TreeNode*> choices = {root};
    backtrack(possibleArrays, path, choices);

    return possibleArrays;
  }

  void backtrack(vector<vector<int>>& results, vector<int>& state,
                 deque<TreeNode*>& choices) {
    if (choices.empty()) {
      results.emplace_back(state);
    }

    int size = choices.size();
    for (size_t i = 0; i < size; i++) {
      TreeNode* choice = choices.front();
      choices.pop_front();

      state.push_back(choice->val);

      if (choice->left != nullptr) choices.push_back(choice->left);
      if (choice->right != nullptr) choices.push_back(choice->right);

      backtrack(results, state, choices);

      if (choice->left != nullptr) choices.pop_back();
      if (choice->right != nullptr) choices.pop_back();
      choices.push_back(choice);
      state.pop_back();
    }
  }
};

int main() {
  Solution s;

  TreeNode* node = new TreeNode(2);
  node->left = new TreeNode(1);
  node->right = new TreeNode(3);
  s.BSTSequences(node);
}

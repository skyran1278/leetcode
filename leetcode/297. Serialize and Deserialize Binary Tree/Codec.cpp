#include <format>
#include <queue>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * @brief 1 hrs 46 m 31 s
 * O(n)
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string s;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      size_t n = q.size();

      for (size_t i = 0; i < n; i++) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          s += format("{:05}", nullValue);
          continue;
        }

        s += format("{:05}", node->val);
        q.push(node->left);
        q.push(node->right);
      }
    }

    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<int> values;

    for (size_t i = 0; i + chunkSize <= data.size(); i += chunkSize) {
      string intValue = data.substr(i, chunkSize);
      values.push_back(stoi(intValue));
    }

    if (values[0] == nullValue) {
      return nullptr;
    }

    TreeNode* root = new TreeNode(values[0]);

    queue<TreeNode*> q;
    q.push(root);

    size_t valueIndex = 1;
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();

      if (node == nullptr) {
        continue;
      }

      if (values[valueIndex] != nullValue) {
        node->left = new TreeNode(values[valueIndex]);
        q.push(node->left);
      }

      if (values[valueIndex + 1] != nullValue) {
        node->right = new TreeNode(values[valueIndex + 1]);
        q.push(node->right);
      }

      valueIndex += 2;
    }

    return root;
  }

 private:
  int chunkSize = 5;
  int nullValue = 11111;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main() {
  Codec s;

  TreeNode* node1 = new TreeNode(4);
  TreeNode* node2 = new TreeNode(5);
  TreeNode* node3 = new TreeNode(2);
  TreeNode* node4 = new TreeNode(3);
  node4->left = node1;
  node4->right = node2;
  TreeNode* node5 = new TreeNode(1);
  node5->left = node3;
  node5->right = node4;
  string s2s = s.serialize(node5);
  TreeNode* s2d = s.deserialize(s2s);

  TreeNode* s1 = nullptr;
  string s1s = s.serialize(s1);
  TreeNode* s1d = s.deserialize(s1s);
}

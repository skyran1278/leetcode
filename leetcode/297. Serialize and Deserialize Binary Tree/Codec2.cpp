#include <queue>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * @brief 12 m 9 s
 * O(n)
 * O(n)
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr) {
      return "null";
    }

    return to_string(root->val) + "," + serialize(root->left) + "," +
           serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    stringstream ss(data);
    queue<string> values;

    string item;
    while (getline(ss, item, ',')) {
      values.push(item);
    }

    return dfs(values);
  }

  // [1,2,null,null,3,4,null,null,4,null,null]
  TreeNode* dfs(queue<string>& values) {
    string value = values.front();
    values.pop();
    if (value == "null") {
      return nullptr;
    }

    TreeNode* node = new TreeNode(stoi(value));
    node->left = dfs(values);
    node->right = dfs(values);

    return node;
  }
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
  s.deserialize(s2s);

  TreeNode* s1 = nullptr;
  string s1s = s.serialize(s1);
  s.deserialize(s1s);
}

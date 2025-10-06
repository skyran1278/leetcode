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

class Codec {
 public:
  // Encodes a tree to a single string.
  // root = [1,2,3,null,null,4,5]
  string serialize(TreeNode* root) {
    string result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      size_t n = q.size();

      for (size_t i = 0; i < n; i++) {
        TreeNode* node = q.front();
        q.pop();

        if (node != nullptr) {
          result += to_string(node->val) + ",";

          q.push(node->left);
          q.push(node->right);
        } else {
          result += "null,";
        }
      }
    }

    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    stringstream ss(data);
    string item;

    getline(ss, item, ',');
    if (item == "null") {
      return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(item));

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      size_t n = q.size();
      for (size_t i = 0; i < n; i++) {
        TreeNode* node = q.front();
        q.pop();

        getline(ss, item, ',');
        if (item != "null") {
          node->left = new TreeNode(stoi(item));
          q.push(node->left);
        }

        getline(ss, item, ',');
        if (item != "null") {
          node->right = new TreeNode(stoi(item));
          q.push(node->right);
        }
      }
    }

    return root;
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
  TreeNode* s2d = s.deserialize(s2s);

  TreeNode* s1 = nullptr;
  string s1s = s.serialize(s1);
  TreeNode* s1d = s.deserialize(s1s);
}

#include <unordered_map>

// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

/**
 * @brief 1 hrs 11 m 19 s
 * O(n)
 */
class Solution {
  std::unordered_map<Node*, Node*> cachedNode;

 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) {
      return nullptr;
    }

    if (!cachedNode[head]) {
      Node* copy = new Node(head->val);
      cachedNode[head] = copy;
      copy->next = copyRandomList(head->next);
      copy->random = cachedNode[head->random];
    }

    return cachedNode[head];
  }
};

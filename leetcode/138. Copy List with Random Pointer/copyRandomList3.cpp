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
 * @brief 44 m 21 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
  Node* copyRandomList(Node* head) {
    Node* runner = head;

    while (runner != nullptr) {
      Node* intervalNode = new Node(runner->val);
      intervalNode->next = runner->next;
      runner->next = intervalNode;
      runner = runner->next->next;
    }
    // head =
    // [[7,null],[7,null],[13,0],[13,null],[11,4],[11,null],[10,2],[10,null],[1,0],[1,null]]

    runner = head;
    while (runner != nullptr) {
      // 1. runner =
      // [[7,null],[7,null],[13,0],[13,null],[11,4],[11,null],[10,2],[10,null],[1,0],[1,null]]
      // [[13,0],[13,0],[11,4],[11,null],[10,2],[10,null],[1,0],[1,null]]
      runner->next->random =
          runner->random == nullptr ? nullptr : runner->random->next;
      // 1. runner =
      // [[13,0],[13,null],[11,4],[11,null],[10,2],[10,null],[1,0],[1,null]]
      // [[11,4],[11,null],[10,2],[10,null],[1,0],[1,null]]
      runner = runner->next->next;
    }
    // head =
    // [[7,null],[7,null],[13,0],[13,0],[11,4],[11,4],[10,2],[10,2],[1,0],[1,0]]

    Node* copy = new Node(0);
    Node* copyRunner = copy;
    runner = head;
    while (runner != nullptr) {
      copyRunner->next = runner->next;
      runner->next = runner->next->next;
      runner = runner->next;
      copyRunner = copyRunner->next;
    }
    // copy =
    // [[0,null],[7,null],[13,0],[11,4],[10,2],[1,0]]

    return copy->next;
  }
};

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
 * @brief 26 m 57 s
 * O(n^2)
 * O(1)
 */
class Solution {
 public:
  // head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
  Node* copyRandomList(Node* head) {
    Node* runner1 = head;
    Node* dummy = new Node(0);
    Node* runner2 = dummy;

    while (runner1 != nullptr) {
      runner2->next = new Node(runner1->val);
      runner2 = runner2->next;
      runner1 = runner1->next;
    }
    // dummy = [[0,null], [7,null],[13,null],[11,null],[10,null],[1,null]]

    runner1 = head;
    runner2 = dummy->next;
    while (runner1 != nullptr) {
      // 1. random = null
      // 2. random = 0
      Node* random = runner1->random;
      if (random != nullptr) {
        Node* randomRunner1 = head;
        Node* randomRunner2 = dummy->next;
        while (random != randomRunner1) {
          randomRunner1 = randomRunner1->next;
          randomRunner2 = randomRunner2->next;
        }
        runner2->random = randomRunner2;
      }

      runner2 = runner2->next;
      runner1 = runner1->next;
    }

    return dummy->next;
  }
};

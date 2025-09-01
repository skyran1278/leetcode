/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  // head = [1, 4, 3, 2, 5, 2], x = 3
  // head = [2, 1], x = 2
  ListNode* partition(ListNode* head, int x) {
    ListNode* l1 = new ListNode();
    ListNode* l1Runner = l1;
    ListNode* l2 = new ListNode();
    ListNode* l2Runner = l2;

    while (head != nullptr) {
      if (head->val < x) {
        // 1. l1Runner = [0, 1, 4, 3, 2, 5, 2]
        // 4. l1Runner = [1, 2, 5, 2]
        // 6. l1Runner = [2, 2]
        l1Runner->next = head;
        // 1. l1Runner = [1, 4, 3, 2, 5, 2]
        // 4. l1Runner = [2, 5, 2]
        // 6. l1Runner = [2]
        l1Runner = l1Runner->next;
      } else {
        // 2. l2Runner = [0, 4, 3, 2, 5, 2]
        // 3. l2Runner = [4, 3, 2, 5, 2]
        // 5. l2Runner = [3, 5, 2]
        l2Runner->next = head;
        // 2. l2Runner = [4, 3, 2, 5, 2]
        // 3. l2Runner = [3, 2, 5, 2]
        // 5. l2Runner = [5, 2]
        l2Runner = l2Runner->next;
      }

      // 1. head = [4, 3, 2, 5, 2]
      // 2. head = [3, 2, 5, 2]
      // 3. head = [2, 5, 2]
      // 4. head = [5, 2]
      // 5. head = [2]
      // 6. head = []
      head = head->next;
    }

    // l2Runner = [5]
    l2Runner->next = nullptr;
    // l1Runner = [2, 4, 3, 5]
    l1Runner->next = l2->next;

    return l1->next;
  }
};

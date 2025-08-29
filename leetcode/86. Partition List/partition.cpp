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
  ListNode* partition(ListNode* head,
                      int x) {  // head = [1, 4, 3, 2, 5, 2], x = 3
    ListNode* current = head;   // node = [1, 4, 3, 2, 5, 2]
    ListNode* tail = head;      // tail = [1, 4, 3, 2, 5, 2]

    // find the x
    while (current != nullptr) {
      if (current->val == x) {
        break;
      }
      current = current->next;
    }

    // current = [3, 2, 5, 2]
    while (current != nullptr && current->next != nullptr) {
      // 1. next = [2, 5, 2]
      ListNode* next = current->next;
      if (next->val < x) {
        // 1. current = [3, 5, 2]
        current->next = next->next;

        //
        next->next = tail->next;
        tail->next = next;
      }
      current = current->next;
    }

    return head;
  }
};

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
  ListNode* partition(ListNode* head, int x) {
    ListNode* l1 = new ListNode();
    ListNode* l1Runner = l1;
    ListNode* l2 = new ListNode();
    ListNode* l2Runner = l2;

    while (head != nullptr) {
      if (head->val < x) {
        l1Runner->next = head;
        l1Runner = l1Runner->next;
      } else {
        l2Runner->next = head;
        l2Runner = l2Runner->next;
      }
      head = head->next;
    }

    l1Runner->next = l2->next;
    l2Runner->next = nullptr;

    return l1->next;
  }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * @brief 33 m 51 s
 * O(n)
 */
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA;
    ListNode *b = headB;

    long aLength = 0;
    while (a->next != nullptr) {
      a = a->next;
      aLength++;
    }

    long bLength = 0;
    while (b->next != nullptr) {
      b = b->next;
      bLength++;
    }

    if (a != b) {
      return nullptr;
    }

    a = headA;
    b = headB;
    if (aLength > bLength) {
      for (long i = 0; i < aLength - bLength; i++) {
        a = a->next;
      }
    } else {
      for (long i = 0; i < bLength - aLength; i++) {
        b = b->next;
      }
    }

    while (a != nullptr) {
      if (a == b) {
        return a;
      }

      a = a->next;
      b = b->next;
    }

    return nullptr;
  }
};

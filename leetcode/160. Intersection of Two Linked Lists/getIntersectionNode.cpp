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
 * @brief 12 m 23 s
 * O(m+n)
 * O(1)
 */
class Solution {
 public:
  // intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2,
  // skipB = 3
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

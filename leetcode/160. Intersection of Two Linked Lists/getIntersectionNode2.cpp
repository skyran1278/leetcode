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
 * @brief AI
 * O(m+n)
 * O(1)
 */
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;

    ListNode *pA = headA;
    ListNode *pB = headB;

    // When one pointer reaches the end, redirect it to the other list's head
    while (pA != pB) {
      pA = pA ? pA->next : headB;
      pB = pB ? pB->next : headA;
    }

    // Either both null (no intersection) or the intersection node
    return pA;
  }
};

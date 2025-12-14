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
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * @brief 1 m 34 s
 * @brief 2 m 32 s
 * O(m+n)
 * O(1)
 */
class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* runnerA = headA;
    ListNode* runnerB = headB;

    while (runnerA != runnerB) {
      runnerA = runnerA != nullptr ? runnerA->next : headB;
      runnerB = runnerB != nullptr ? runnerB->next : headA;
    }

    return runnerA;
  }
};

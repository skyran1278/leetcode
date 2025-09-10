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
 * @brief 21 m 38 s
 * @brief 15 m 20 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // head = [3,2,0,-4], pos = 1
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != nullptr && fast->next != nullptr) {
      // fast = 0
      // fast = 2
      // fast = -4
      fast = fast->next->next;
      // slow = 2
      // slow = 0
      // slow = -4
      slow = slow->next;

      if (fast == slow) {
        break;
      }
    }

    if (fast == nullptr || fast->next == nullptr) {
      return nullptr;
    }

    ListNode *runner = head;

    while (runner != fast) {
      // runner = 2
      runner = runner->next;
      // fast = 2
      fast = fast->next;
    }

    return runner;
  }
};

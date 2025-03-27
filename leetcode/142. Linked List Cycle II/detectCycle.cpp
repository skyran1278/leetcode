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
 * O(n)
 */
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fastRunner = head;
    ListNode *slowRunner = head;
    while (fastRunner != nullptr && fastRunner->next != nullptr) {
      fastRunner = fastRunner->next->next;
      slowRunner = slowRunner->next;

      if (fastRunner == slowRunner) {
        break;
      }
    }

    if (fastRunner == nullptr || fastRunner->next == nullptr) {
      return nullptr;
    }

    fastRunner = head;

    while (fastRunner != nullptr) {
      if (fastRunner == slowRunner) {
        return fastRunner;
      }
      fastRunner = fastRunner->next;
      slowRunner = slowRunner->next;
    }

    return nullptr;
  }
};

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

/**
 * @brief 9 m 16 s
 * O(n)
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
  ListNode* middleNode(ListNode* head) {
    ListNode* fastRunner = head;
    ListNode* slowRunner = head;

    while (fastRunner != nullptr && fastRunner->next != nullptr) {
      fastRunner = fastRunner->next->next;
      slowRunner = slowRunner->next;
    }

    return slowRunner;
  }
};

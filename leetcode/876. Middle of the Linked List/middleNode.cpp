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

/**
 * @brief 9 m 16 s
 * @brief 3 m 35 s
 * @brief 1 m 18 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // head = [1,2,3,4,5,6]
  ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
      // slow = [2,3,4,5,6]
      // slow = [3,4,5,6]
      // slow = [4,5,6]
      slow = slow->next;

      // fast = []
      fast = fast->next->next;
    }

    return slow;
  }
};

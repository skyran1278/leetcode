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
 * @brief
 * O(n)
 * O(1)
 */
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {  // [1, 2, 3, 4, 5]
    ListNode* prev = nullptr;

    while (head != nullptr) {
      // 1. next = [2, 3, 4, 5]
      // 2. next = [3, 4, 5]
      ListNode* next = head->next;

      // 1. prev = [1]
      // 2. prev = [2, 1]
      head->next = prev;
      prev = head;

      // 1. head = [2, 3, 4, 5]
      // 2. head = [3, 4, 5]
      head = next;
    }

    return prev;
  }
};

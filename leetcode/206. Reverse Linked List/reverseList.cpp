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
 * @brief 15 m 2 s
 *
 */
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {  // [1, 2, 3, 4, 5]
    ListNode* node = nullptr;

    while (head != nullptr) {
      // 1. current = [1, 2, 3, 4, 5]
      // 2. [2, 3, 4, 5]
      // 3. [3, 4, 5]
      // 4. [4, 5]
      // 5. [5]
      ListNode* current = head;
      // 1. head = [2, 3, 4, 5]
      // 2. [3, 4, 5]
      // 3. [4, 5]
      // 4. [5]
      // 5. []
      head = head->next;
      // 1. current = [1]
      // 2. [2, 1]
      // 3. [3, 2, 1]
      // 4. [4, 3, 2, 1]
      // 5. [5, 4, 3, 2, 1]
      current->next = node;
      node = current;
    }

    return node;
  }
};

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
 * @brief 12 m 50 s
 *
 */
class Solution {
 public:
  // list1 = [1, 2, 4]
  // list2 = [1, 3, 4]
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode();  // dump = 0
    ListNode* tail = dummy;            // node = 0

    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        tail->next = list1;  // 1. node = [0 1 2 4] 3. [1, 2, 4] 5. [3, 4]

        list1 = list1->next;  // 1. list1 = [2, 4] 3. [4] 5. []
      } else {
        tail->next = list2;  // 2. node = [1, 1, 3, 4] 4. [2, 3, 4]

        list2 = list2->next;  // 2. list2 = [3, 4] 4. [4]
      }

      tail = tail->next;  // 1. node = [1, 2, 4] 2. [1, 3, 4] 3. [2, 4] 4. [3,
                          // 4] 5. [4]
    }

    if (list1 != nullptr) {
      tail->next = list1;
    }

    if (list2 != nullptr) {
      tail->next = list2;  // [4, 4]
    }

    return dummy->next;
  }
};

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

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* n = head->next;
    head->next = swapPairs(head->next->next);
    n->next = head;
    return n;
  }
};

class Solution2 {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
      a->next = b->next;
      b->next = a;
      *pp = b;
      pp = &(a->next);
    }
    return head;
  }
};

int main() {
  Solution2 solution;
  ListNode* list =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  ListNode* swapPairsList = solution.swapPairs(list);
}

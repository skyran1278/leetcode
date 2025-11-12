#include <algorithm>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * @brief 33 m 21 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // 1->2->2->1
  bool isPalindrome(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast && fast->next) {
      fast = fast->next->next;  // fast = null
      slow = slow->next;        // slow = 2->1
    }

    slow = reverse(slow);  // slow = 1->2
    while (slow) {
      if (slow->val != head->val) return false;
      slow = slow->next;
      head = head->next;
    }

    return true;
  }

  ListNode* reverse(ListNode* current) {
    ListNode* prev = nullptr;

    while (current) {
      ListNode* next = current->next;  // next = null
      current->next = prev;            // current = 1 -> 2 -> null
      prev = current;                  // prev = 1 -> 2 -> null
      current = next;                  // current = null
    }

    return prev;
  }
};

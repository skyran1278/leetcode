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
 * @brief 14 m 34 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  // (7 -> 1 -> 6) + (5 -> 9 -> 2)
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* tail = dummy;
    int carry = 0;
    while (l1 || l2 || carry != 0) {
      // sum = 9
      int sum = carry;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }

      carry = sum / 10;  // carry = 0
      tail->next = new ListNode(sum % 10);
      tail = tail->next;  // dummy = 0 -> 2 -> 1 -> 9
    }

    return dummy->next;
  }
};

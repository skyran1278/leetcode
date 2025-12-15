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
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * @brief 11 m 58 s
 * @brief 56 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // head = [3,2,0,-4], pos = 1
  ListNode* detectCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast && fast->next) {
      fast = fast->next->next;  // fast = -4
      slow = slow->next;        // slow = -4

      if (slow == fast) break;
    }

    if (!fast || !fast->next) return nullptr;

    fast = head;
    while (fast != slow) {
      fast = fast->next;  // fast = 2
      slow = slow->next;  // slow = 2
    }

    return fast;
  }
};

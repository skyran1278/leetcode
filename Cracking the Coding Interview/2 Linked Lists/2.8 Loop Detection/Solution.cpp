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
 * @brief 11m 58s
 * @brief 56s
 * @brief 14m 5s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    do {
      if (!fast || !fast->next) return nullptr;

      fast = fast->next->next;
      slow = slow->next;
    } while (fast != slow);

    fast = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }

    return fast;
  }
};

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
 * @brief 7 m 10 s
 * @brief 7 m 27 s
 * O(n^2)
 * O(n)
 */
class Solution {
 public:
  // [1, 2, 3, 3, 2, 1]
  ListNode* removeDuplicateNodes(ListNode* head) {
    ListNode* current = head;  // [1, 2, 3, 3, 2, 1]
    while (current) {
      ListNode* runner = current;  // [2, 3, 3]

      while (runner != nullptr && runner->next != nullptr) {
        if (runner->next->val == current->val) {
          runner->next = runner->next->next;  // [3]
        } else {
          runner = runner->next;  // [3, 3]
        }
      }

      current = current->next;  // [2, 3]
    }

    return head;
  }
};

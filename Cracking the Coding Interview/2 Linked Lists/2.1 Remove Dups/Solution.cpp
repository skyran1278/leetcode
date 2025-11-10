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
 * @brief 24 m 29 s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  // [1, 2, 3, 3, 2, 1]
  ListNode* removeDuplicateNodes(ListNode* head) {
    ListNode* dummy = new ListNode();
    ListNode* dummyRunner = dummy;

    unordered_map<int, bool> map;

    ListNode* current = head;  // [1, 2, 3, 3, 2, 1]
    while (current != nullptr) {
      if (!map[current->val]) {
        dummyRunner->next = current;      // [2, 3, 3, 2, 1]
        dummyRunner = dummyRunner->next;  // [3, 3, 2, 1]
        map[current->val] = true;         // 1: true, 2: true, 3: true
      }
      current = current->next;  // [3, 2, 1]
    }

    dummyRunner->next = nullptr;

    return dummy->next;
  }
};

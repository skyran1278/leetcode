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
 * @brief 24m 29s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  // [1, 2, 3, 3, 2, 1]
  ListNode* removeDuplicateNodes(ListNode* head) {
    unordered_set<int> map;

    ListNode* runner = head;  // [1, 2, 3, 3, 2, 1]
    ListNode* prev = nullptr;
    while (runner != nullptr) {
      if (map.count(runner->val)) {
        prev->next = runner->next;  // [3]
      } else {
        map.insert(runner->val);  // 1, 2, 3
        prev = runner;            // [3, 3, 2, 1]
      }

      runner = runner->next;  // []
    }

    return head;
  }
};

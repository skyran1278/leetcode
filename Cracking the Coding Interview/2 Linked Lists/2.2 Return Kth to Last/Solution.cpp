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
 * @brief 3 m 36 s
 * @brief 1 m 40 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // 1->2->3->4->5 和 k = 2
  int kthToLast(ListNode* head, int k) {
    ListNode* kNode = head;
    ListNode* tail = head;

    for (size_t i = 0; i < k; i++) {
      tail = tail->next;  // 3->4->5
    }

    while (tail != nullptr) {
      kNode = kNode->next;  // 4->5
      tail = tail->next;    //
    }

    return kNode->val;
  }
};

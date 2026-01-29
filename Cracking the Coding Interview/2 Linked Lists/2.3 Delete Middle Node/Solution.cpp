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
 * @brief 48 s
 * @brief 1 m 12 s
 * O(1)
 * O(1)
 */
class Solution {
 public:
  void deleteNode(ListNode* node) {
    ListNode* next = node->next;

    node->val = next->val;
    node->next = next->next;

    delete next;
  }
};

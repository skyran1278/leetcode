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
 * @brief 12 m 18 s
 * @brief 4 m 4 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // listA = [4,1,8,4,5], listB = [5,0,1,8,4,5]
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* tailA = headA;
    ListNode* tailB = headB;
    while (tailA != tailB) {
      tailA = tailA ? tailA->next : headB;  // tailA = 8
      tailB = tailB ? tailB->next : headA;  // tailB = 8
    }

    return tailA;
  }
};

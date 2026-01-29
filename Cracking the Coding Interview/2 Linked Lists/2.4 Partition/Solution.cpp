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
 * @brief 10 m 5 s
 * @brief 9 m 50 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  // head = 3->5->8->5->10->2->1, x = 5
  ListNode* partition(ListNode* head, int x) {
    ListNode* l1 = new ListNode();
    ListNode* l1Runner = l1;
    ListNode* l2 = new ListNode();
    ListNode* l2Runner = l2;

    while (head != nullptr) {
      if (head->val < x) {
        l1Runner->next = head;  // l1 = 0->3->2->1
        l1Runner = l1Runner->next;
      } else {
        l2Runner->next = head;  // l2 = 0->5->8->5->10->2->1
        l2Runner = l2Runner->next;
      }
      head = head->next;  // head = 2->1
    }

    l2Runner->next = nullptr;  // l2 = 0->5->8->5->10
    l1Runner->next = l2->next;

    return l1->next;
  }
};

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
class ListNode {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
const addTwoNumbers = (l1, l2) => {
  const lAdd = new ListNode(0);
  let head = lAdd;

  let sum = 0;
  let carry = 0;

  while (l1 !== null || l2 !== null || sum !== 0) {
    if (l1 !== null) {
      sum += l1.val;
      l1 = l1.next;
    }
    if (l2 !== null) {
      sum += l2.val;
      l2 = l2.next;
    }
    if (sum >= 10) {
      sum -= 10;
      carry = 1;
    }

    head.next = new ListNode(sum);
    head = head.next;

    sum = carry;
    carry = 0;
  }

  return lAdd.next;
};

const l1 = new ListNode(2);
l1.next = new ListNode(4);
l1.next.ext = new ListNode(3);

const l2 = new ListNode(5);
l2.next = new ListNode(6);
l2.next.ext = new ListNode(4);
console.log(addTwoNumbers(l1, l2));

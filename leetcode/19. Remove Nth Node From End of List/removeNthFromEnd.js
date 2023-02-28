/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
function ListNode(val) {
  this.val = val;
  this.next = null;
}

const arrayToListNode = (arr) => {
  const head = new ListNode(0);
  let list = head;
  arr.forEach((v) => {
    list.next = new ListNode(v);
    list = list.next;
  });
  return head.next;
};

/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
const removeNthFromEnd = (head, n) => {
  const list = { next: head };
  let p1 = list;
  let p2 = list;

  for (let i = 0; i < n; i += 1) {
    p1 = p1.next;
  }

  while (p1.next !== null) {
    p1 = p1.next;
    p2 = p2.next;
  }

  p2.next = p2.next.next;
  return list.next;
};

console.log(removeNthFromEnd(arrayToListNode([1, 2, 3, 4, 5]), 2));
console.log(removeNthFromEnd(arrayToListNode([1]), 1));
console.log(removeNthFromEnd(arrayToListNode([1, 2]), 2));

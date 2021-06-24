/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

const arrayToListNode = (arr) => {
  const head = new ListNode();
  let list = head;
  arr.forEach((v) => {
    list.next = new ListNode(v);
    list = list.next;
  });
  return head.next;
};

const listNodeToArray = (listNode) => {
  const array = [];
  const recursive = (list) => {
    if (list === null) {
      return;
    }
    array.push(list.val);
    recursive(list.next);
  };
  recursive(listNode);
  return array;
};

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
const swapPairsV2 = (head) => {
  // head: 1 -> 2 -> 3 -> 4
  const list = new ListNode();
  // list: 0 -> null
  let tail = list;
  // tail: 0 -> null
  while (head && head.next) {
    tail.next = new ListNode(head.next.val);
    // tail: 0 -> 2 -> null
    tail = tail.next;
    // tail: 2 -> null
    tail.next = new ListNode(head.val);
    // tail: 2 -> 1 -> null
    tail = tail.next;
    // tail: 1 -> null
    head = head.next.next;
    // head: 3 -> 4
  }
  if (head) {
    tail.next = new ListNode(head.val);
  }
  return list.next;
};

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
const swapPairs = (head) => {
  if (head == null || head.next == null) return head;
  const n = head.next;
  head.next = swapPairs(head.next.next);
  n.next = head;
  return n;
};

// console.log(listNodeToArray(swapPairs(arrayToListNode([]))));
// console.log(listNodeToArray(swapPairs(arrayToListNode([1]))));
console.log(listNodeToArray(swapPairs(arrayToListNode([1, 2, 3, 4]))));
//

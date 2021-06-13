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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
const mergeTwoLists = (l1, l2) => {
  const list = new ListNode();
  let l = list;
  while (l1 !== null || l2 !== null) {
    if (l2 === null) {
      l.next = new ListNode(l1.val);
      l = l.next;
      l1 = l1.next;
    } else if (l1 === null) {
      l.next = new ListNode(l2.val);
      l = l.next;
      l2 = l2.next;
    } else if (l1.val < l2.val) {
      l.next = new ListNode(l1.val);
      l = l.next;
      l1 = l1.next;
    } else {
      l.next = new ListNode(l2.val);
      l = l.next;
      l2 = l2.next;
    }
  }
  return list.next;
};

console.log(
  listNodeToArray(
    mergeTwoLists(
      arrayToListNode([1, 2, 3, 4, 5, 7]),
      arrayToListNode([2, 3, 4, 5, 6])
    )
  )
);

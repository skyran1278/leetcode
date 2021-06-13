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
  let tail = list;
  while (l1 !== null && l2 !== null) {
    if (l1.val < l2.val) {
      tail.next = new ListNode(l1.val);
      l1 = l1.next;
    } else {
      tail.next = new ListNode(l2.val);
      l2 = l2.next;
    }
    tail = tail.next;
  }

  tail.next = l1 || l2;

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

console.log(
  listNodeToArray(mergeTwoLists(arrayToListNode([]), arrayToListNode([])))
);

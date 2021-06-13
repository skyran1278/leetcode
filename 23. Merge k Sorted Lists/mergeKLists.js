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
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
const mergeKLists = (lists) => {
  const list = new ListNode();
  let tail = list;
  lists = lists.filter((list) => list);
  while (lists.length !== 0) {
    let min = Infinity;
    let minIndex = 0;
    for (let i = 0; i < lists.length; i += 1) {
      const listNode = lists[i];
      if (listNode.val < min) {
        min = listNode.val;
        minIndex = i;
      }
    }
    tail.next = new ListNode(lists[minIndex].val);
    tail = tail.next;
    lists[minIndex] = lists[minIndex].next;
    if (lists[minIndex] === null) {
      lists.splice(minIndex, 1);
    }
  }
  return list.next;
};

console.log(
  listNodeToArray(
    mergeKLists([
      arrayToListNode([1, 4, 5]),
      arrayToListNode([1, 3, 4]),
      arrayToListNode([2, 6]),
    ])
  )
);

console.log(listNodeToArray(mergeKLists([])));

console.log(
  listNodeToArray(mergeKLists([arrayToListNode([]), arrayToListNode([])]))
);

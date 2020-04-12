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
  if (head.next === null) return null;
  let list = head;

  // 計算總共有幾個
  let i = 1;
  while (list.next !== null) {
    // 不影響 head
    list = list.next;
    i += 1;
  }

  // 正的數過來要刪除的前一個
  i -= (n + 1);

  // 如果 -1 直接刪除第一個，並回傳
  if (i === -1) {
    return head.next;
  }

  // 正的數過來要刪除的前一個 ListNode
  list = head;
  while (i > 0) {
    list = list.next;
    i -= 1;
  }

  // 會影響 head
  // 要刪除的前一個的 next 直接跳到下下個 ListNode
  list.next = list.next.next;
  return head;
};

console.log(removeNthFromEnd(arrayToListNode([1, 2, 3, 4, 5]), 5));
console.log(removeNthFromEnd(arrayToListNode([1]), 1));
console.log(removeNthFromEnd(arrayToListNode([1, 2]), 2));
